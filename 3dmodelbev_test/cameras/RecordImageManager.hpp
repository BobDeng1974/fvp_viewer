#pragma once
#include <iostream>
#include <string>
#include <atomic>
#include <chrono>


// singleton RecordImageManager CLASS
class RecordImageManager {
private:
	RecordImageManager()//�R���X�g���N�^�� private �ɒu��
	{
		std::cout << "initialize RecordImageManager : " << std::endl;
	};					
	~RecordImageManager() = default;					//�f�X�g���N�^�� private �ɒu��
public:
	RecordImageManager(const RecordImageManager&) = delete;			//�R�s�[�R���X�g���N�^�� delete �w��
	RecordImageManager& operator=(const RecordImageManager&) = delete;	//�R�s�[������Z�q�� delete �w��
	RecordImageManager(RecordImageManager&&) = delete;			//���[�u�R���X�g���N�^�� delete �w��
	RecordImageManager& operator=(RecordImageManager&&) = delete;		//���[�u������Z�q�� delete �w��

	static RecordImageManager& getInstance() {
		static RecordImageManager inst;			// private�ȃR���X�g���N�^���Ăяo��
		return inst;
	}

	void setRecordFolder(const std::string dirname, int fps) {
	};
	std::string getRecordFolder() const {
		return "Not implemented";
	};

	//-----------------------------------------------------------------------------
	bool isRecorded() const {
		//return _isRecorded;
		return false;
	}

	//-----------------------------------------------------------------------------
	
	bool already_create_directory = false;
	void stopRecord() {};
	void startRecord() {};
	double getElapsedSec() { return 0.0; };
private:

	//void makeDirectory();

	//-----------------------------------------------------------------------------
	//
	bool isStopRecord = false;
	std::atomic<bool> _isRecorded = false;
	std::string record_foldername;
	std::chrono::system_clock::time_point  time_start; // �^�� auto �ŉ�
	double recorded_time = 0.0;
};
