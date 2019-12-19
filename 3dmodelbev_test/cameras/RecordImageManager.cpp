//#include "RecordImageManager.hpp"
//
//#include <boost/date_time.hpp>
//#include <boost/filesystem.hpp>
//
//// record raw folder
//namespace fs = boost::filesystem;
//namespace pt = boost::posix_time;
////-----------------------------------------------------------------------------
//void RecordImageManager::setRecordFolder(const std::string dirname, int fps)
//{
//	// �t�H�[�}�b�g�̎w��
//	// facet �̓X�g���[�����Ŏ����I�� delete �����
//	auto facet = new pt::time_facet("%Y%m%d_%H%M%S");
//	std::stringstream ss;
//	ss.imbue(std::locale(std::cout.getloc(), facet));
//
//	// ���݂̎������擾
//	auto now_time = pt::second_clock::local_time();
//	ss << now_time;
//
//	// �^��p�t�H���_���̐ݒ�
//	record_foldername = dirname + "/"
//		+ ss.str() + "_" + std::to_string(fps) + "fps";
//
//}
////-----------------------------------------------------------------------------
//void RecordImageManager::makeDirectory()
//{
//	// �^��p�t�H���_�̊m�F
//	if (!already_create_directory) {
//		std::cout << "\n/ ********\ncreate directory : "
//			<< record_foldername << "\n***********/" << std::endl;
//
//		const fs::path path(record_foldername);
//
//		boost::system::error_code error;
//		const bool result = fs::create_directories(path, error);
//		if (!result || error) {
//			std::cout << "�f�B���N�g���̍쐬�Ɏ��s" << std::endl;
//		}
//		already_create_directory = true;
//	}
//}
////-----------------------------------------------------------------------------
//std::string RecordImageManager::getRecordFolder() const {
//	return record_foldername;
//}
////-----------------------------------------------------------------------------
//void RecordImageManager::startRecord() {
//
//	// if the directory exists, do nothing
//	makeDirectory();
//
//	std::cout << "**** save raw data in the following directory! *******\n";
//	std::cout << record_foldername << std::endl;
//	_isRecorded = true;
//
//	// save start time
//	time_start = std::chrono::system_clock::now();
//}
////-----------------------------------------------------------------------------
//void RecordImageManager::stopRecord() {
//	std::cout << "\n**** stop record! *******\n";
//
//	_isRecorded = false;
//	auto end = std::chrono::system_clock::now();  // �v���I������
//	//�����ɗv�������Ԃ�b�ɕϊ�
//	double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - time_start).count()/1000.0; 
//	recorded_time += elapsed;
//}
////-----------------------------------------------------------------------------
//double RecordImageManager::getElapsedSec()
//{
//	if (_isRecorded)
//	{
//		auto end = std::chrono::system_clock::now();  // �v���I������
//		 //�����ɗv�������Ԃ�b�ɕϊ�
//		double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - time_start).count() / 1000.0;
//		return recorded_time + elapsed;
//	}
//	else
//	{
//		return recorded_time;
//	}
//}
////-----------------------------------------------------------------------------
