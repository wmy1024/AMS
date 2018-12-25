#include "default_best_group.h"
#include "best_message.h"
#include "default_message_pool.h"
#include "default_best_group.h"
/************************IBestBase�ӿ�*************************/
///�������ü�������������
IBestBase*  BEST_FUNCTION_CALL_MODE DefaultBestGroup::AddRef(){
	++m_ref;
	return this;
}

///�������ü�������Ϊ0ʱ�ͷ�����
uint64  BEST_FUNCTION_CALL_MODE DefaultBestGroup::Release(){
	if (--m_ref == 0)delete this;
	return 0;
}

///����BEST��������
BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE DefaultBestGroup::GetBestType()
{ 
	return OBJ_NONE; 
}

///������������
int32 BEST_FUNCTION_CALL_MODE DefaultBestGroup::SetOwner(IBestBase* best_base)
{
	return 0;
}

///��ȡ��������
IBestBase* BEST_FUNCTION_CALL_MODE DefaultBestGroup::GetOwner()
{
	return 0;
}

/****************************IBestStream�ӿ�******************************/
///���л�����
const void*  BEST_FUNCTION_CALL_MODE DefaultBestGroup::Serialize(int32* len)
{
	return 0;
}
///�����л�
int32 BEST_FUNCTION_CALL_MODE DefaultBestGroup::Deserialize()
{
	return 0;
}

///������
int32	BEST_FUNCTION_CALL_MODE DefaultBestGroup::SetBuffer(const void* buffer, const int32& len)
{
	return 0;
}
///��ȡ��
void*  BEST_FUNCTION_CALL_MODE DefaultBestGroup::GetBuffer(int32* len)
{
	return 0;
}
///������״̬. 1:���� 0:������
int32  BEST_FUNCTION_CALL_MODE DefaultBestGroup::Status()
{
	return 0;
}
///�������л���
int32   BEST_FUNCTION_CALL_MODE DefaultBestGroup::SetBestSerializer(IBestSerializer* serializer)
{
	return 0;
}
///��ȡ���л���

IBestSerializer* BEST_FUNCTION_CALL_MODE DefaultBestGroup::GetBestSerializer()
{
	return 0;
}
///����һ����¼,�������Ӻ�ļ�¼����
IBestRecord * BEST_FUNCTION_CALL_MODE DefaultBestGroup::AddRecord()
{
	return 0;
}
///����һ���Ѵ��ڵļ�¼
int BEST_FUNCTION_CALL_MODE DefaultBestGroup::AddRecord(IBestRecord * best_record)
{
	return 0;
}

///��ȡ��¼������
DefaultBestIterator* BEST_FUNCTION_CALL_MODE DefaultBestGroup::GetIterator()
{
	return 0;
}

///����һ�������Ƶ�����
int32 BEST_FUNCTION_CALL_MODE DefaultBestGroup::CopyFrom(const IBestGroup* other)
{
	return 0;
}

///��������
IBestGroup* BEST_FUNCTION_CALL_MODE DefaultBestGroup::Clone() const
{
	return 0;
}

// ��ȡ��ǰ�ֶε�Э��
const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE DefaultBestGroup::GetProtocal()
{ 
	return m_protocal_type;
}

//����Э������
int32 BEST_FUNCTION_CALL_MODE DefaultBestGroup::SetProtocal(PROTOCAL_TYPE protpcal)
{
	m_protocal_type = protpcal;
	return 0;
}
