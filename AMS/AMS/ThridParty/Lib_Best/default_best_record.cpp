#include "default_best_group.h"
#include "best_message.h"
#include "default_message_pool.h"
#include "default_best_record.h"
/************************IBestBase�ӿ�*************************/
using namespace best_protocol;
///��ȡ$tag���ֶ�,NULL��ʾ������
IBestField*  BEST_FUNCTION_CALL_MODE DefaultBestRecord::GetField(const int32& tag)
{
	return 0;
}
///����$tag���ֶ�
void BEST_FUNCTION_CALL_MODE DefaultBestRecord::SetField(const int32& tag, IBestField* field)
{
	
}
///�ж�$tag���ֶ��Ƿ����
bool BEST_FUNCTION_CALL_MODE DefaultBestRecord::IsExistField(const int32& tag)
{
	return 0;
}
///����һ�������Ƶ�����
int32 BEST_FUNCTION_CALL_MODE DefaultBestRecord::CopyFrom(const IBestRecord *other)
{
	return 0;
}
///��������
IBestRecord* BEST_FUNCTION_CALL_MODE DefaultBestRecord::Clone()
{
	return 0;
}
///��ȡ�ֶε�����
DefaultBestIterator* BEST_FUNCTION_CALL_MODE DefaultBestRecord::GetIterator()
{
	return 0;
}

/************************IBestBase�ӿ�*************************/
///�������ü�������������
IBestBase*  BEST_FUNCTION_CALL_MODE DefaultBestRecord::AddRef(){
	++m_ref;
	return this;
}

///�������ü�������Ϊ0ʱ�ͷ�����
uint64  BEST_FUNCTION_CALL_MODE DefaultBestRecord::Release(){
	if (--m_ref == 0)delete this;
	return 0;
}

///����BEST��������
BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE DefaultBestRecord::GetBestType()
{ 
	return OBJ_NONE; 
}

///������������
int32 BEST_FUNCTION_CALL_MODE DefaultBestRecord::SetOwner(IBestBase* best_base)
{ 
	return 0; 
}

///��ȡ��������
IBestBase* BEST_FUNCTION_CALL_MODE DefaultBestRecord::GetOwner()
{ 
	return 0; 
}

/****************************IBestStream�ӿ�******************************/
///���л�����
const void*  BEST_FUNCTION_CALL_MODE DefaultBestRecord::Serialize(int32* len)
{ 
	return 0; 
}
///�����л�
int32 BEST_FUNCTION_CALL_MODE DefaultBestRecord::Deserialize()
{ 
	return 0; 
}

///������
int32	BEST_FUNCTION_CALL_MODE DefaultBestRecord::SetBuffer(const void* buffer, const int32& len)
{ 
	return 0; 
}
///��ȡ��
void*  BEST_FUNCTION_CALL_MODE DefaultBestRecord::GetBuffer(int32* len)
{ 
	return 0; 
}
///������״̬. 1:���� 0:������
int32  BEST_FUNCTION_CALL_MODE DefaultBestRecord::Status()
{ 
	return 0; 
}
///�������л���
int32   BEST_FUNCTION_CALL_MODE DefaultBestRecord::SetBestSerializer(IBestSerializer* serializer)
{ 
	return 0; 
}
///��ȡ���л���
IBestSerializer* BEST_FUNCTION_CALL_MODE DefaultBestRecord::GetBestSerializer()
{ 
	return 0; 
}

/// ��ȡ��ǰ�ֶε�Э��
const PROTOCAL_TYPE DefaultBestRecord::GetProtocal()
{
	return m_protocol_type;
}

int32 DefaultBestRecord::SetProtocal(PROTOCAL_TYPE protpcal)
{
	m_protocol_type = protpcal;
	return 0;
}
