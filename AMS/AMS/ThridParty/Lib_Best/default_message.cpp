#include "default_message.h"
#include "default_best_message_factory.h"
#include "default_message_pool.h"
///*******************��ȡ�����ö�Ӧ��Record�ֶ�ֵ*********************/
//IBestField* DefaultBestRecord::GetField(const int32& tag)
//{
//	return 0;
//}
//
/////����$tag���ֶ�
//void DefaultBestRecord::SetField(const int32& tag, IBestField* field)
//{
//
//}
//
/////�ж�$tag���ֶ��Ƿ����
//bool DefaultBestRecord::IsExistField(const int32& tag)
//{
//	return true;
//}
//
/////����һ�������Ƶ�����
//int32 DefaultBestRecord::CopyFrom(const IBestRecord *other)
//{
//	return 0;
//}
/////��������
//IBestRecord* DefaultBestRecord::Clone()
//{
//	return 0;
//}
//
//DefaultBestIterator*   DefaultBestRecord::GetIterator()
//{
//	return &m_defaultIterator;
//}

IBestMessgeFactory*  BEST_FUNCTION_CALL_MODE CreateBestMessgeFactrotyInstance()
{
	return DefaultBestMessgeFactory::GetInstance();
}

int32  BEST_FUNCTION_CALL_MODE InitBestMessge()
{
	DefaultMessagePool::InitDefaultMessagePool();
	return 0;
}



