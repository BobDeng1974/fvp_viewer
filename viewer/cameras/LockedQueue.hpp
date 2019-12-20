#pragma  once
#include <mutex>
#include <condition_variable>
#include <deque>

// Consumer and Producer
template <class T>
struct LockedQueue {
	// �R���X�g���N�^�ɁA�L���[�̑傫�����w��
	explicit LockedQueue(int capacity)
		: capacity(capacity)
	{}

	// �L���[��x��������
	void enqueue(const T& x) {
		std::unique_lock<std::mutex> lock(m);
		// �O����notify_all()�܂���notify_one()�ɂ���ċN�������܂Ńu���b�N���đ҂�
		// �������A�N�����ꂽ���ɃL���[�����t�������ꍇ�́A�܂��u���b�N���đ҂�
		c_enq.wait(lock, [this] { return data.size() != capacity; });
		data.push_back(x);
		// dequeue�̏������ł������Ƃ�ʒm
		c_deq.notify_one();
	}

	// �L���[����v�f�����o��
	T dequeue() {
		std::unique_lock<std::mutex> lock(m);
		// �O����notify_all()�܂���notify_one()�ɂ���ċN�������܂Ńu���b�N���đ҂�
		// �������A�N�����ꂽ���ɃL���[����ł���ꍇ�́A�܂��u���b�N���đ҂�
		c_deq.wait(lock, [this] { return !data.empty(); });
		T ret = data.front();
		data.pop_front();
		// enqueue�̏������ł������Ƃ�ʒm
		c_enq.notify_one();
		return ret;
	}

	// data size �̎擾
	size_t getCurrentDataSize()
	{
		return data.size();
	}

private:
	std::mutex m;
	std::deque<T> data;
	size_t capacity;
	std::condition_variable c_enq;
	std::condition_variable c_deq;
};