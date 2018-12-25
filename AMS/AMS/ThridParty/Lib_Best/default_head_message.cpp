#include "default_head_message.h"
#include "default_message_pool.h"
#include "default_serializer.h"
#include "default_best_field.h"
#include "default_best_message_factory.h"
#include <map>

///��ȡͷ������,0��ʾ��ǰ�޷���ȡͷ������
int32 DefaultBestHeadMessage::GetHeadLength()
{ 
	return m_best_head_struct.head_length; 
}

///��ȡ���ݳ���,0��ʾ��ǰ�޷���ȡ���ݳ���
int32 DefaultBestHeadMessage::GetDataLength() 
{ 
	return m_best_head_struct.content_length;
}


void DefaultBestHeadMessage::SetDataLength(int32 data_lenght)
{
	m_best_head_struct.content_length = data_lenght;
}
/******************************************�������ݲ�******************************************/
///�������ݲ���Ϣ
int32 DefaultBestHeadMessage::SetDataMessage(IBestDataMessage* data_msg)
{ 
	m_data_msg = (DefaultBestDataMessage*)data_msg;
	return 0; 
}
///��ȡ���ݲ���Ϣ
IBestDataMessage* DefaultBestHeadMessage::GetDataMessage(){ return m_data_msg; }
///����һ����Ϣ���Ƶ�����
int32 DefaultBestHeadMessage::CopyFrom(const IBestHeadMessage* other) { 
	DefaultBestHeadMessage* head_message = (DefaultBestHeadMessage*)(other);
	m_best_head_struct = head_message->m_best_head_struct;
	m_protocol_type = head_message->m_protocol_type;
	std::map<int, IBestField*>::iterator itor;
	itor = m_best_field_map.begin();
	for (; itor != m_best_field_map.end(); ++itor)
	{
		itor->second->Release();
	}
	m_best_field_map.clear();
	itor = head_message->m_best_field_map.begin();
	for (; itor != head_message->m_best_field_map.end(); ++itor)
	{
		this->GetField(itor->first)->CopyFrom(itor->second);
	}
	IBestDataMessage* data_message = head_message->GetDataMessage();
	if (data_message != NULL)
	{
		IBestDataMessage* self_data_message = GetDataMessage();
		if (self_data_message != NULL)
		{
			self_data_message->Release();
		}
		this->SetDataMessage(DefaultMessagePool::AcquireDefaultBestDataMessage());
		GetDataMessage()->CopyFrom(data_message);
	}
	
	return 0; 
}
///��������
IBestHeadMessage* DefaultBestHeadMessage::Clone(){
	DefaultBestHeadMessage* headMessge = DefaultMessagePool::AcquireDefaultBestHeadMessage();
	headMessge->CopyFrom(this);
	return headMessge;
}
/**********************************��ȡ������*************************/
///��ȡ$tag���ֶ�,NULL��ʾ������
IBestField*   DefaultBestHeadMessage::GetField(const int32& tag)
{ 
	std::map<int, IBestField*>::iterator field_itor = m_best_field_map.find(tag);
	if (field_itor != m_best_field_map.end())
	{
		return field_itor->second;
	}
	else
	{
		IBestField* best_field = (DefaultBestField*)DefaultMessagePool::AcquireDefaultBestField();
		((DefaultBestField*)best_field)->SetTag(tag);
		m_best_field_map[tag] = best_field;
		return best_field;
	}
}

///����$tag���ֶ�
void DefaultBestHeadMessage::SetField(const int32& tag, IBestField* field) 
{ 
	m_best_field_map[tag] = field;
}

///�ж�$tag���ֶ��Ƿ����
bool DefaultBestHeadMessage::IsExistField(const int32& tag) 
{ 
	std::map<int, IBestField*>::iterator itor = m_best_field_map.find(tag);
	if (itor != m_best_field_map.end())
	{
		return true;
	}
	return false; 
}

uint64  DefaultBestHeadMessage::Release()
{
	if (m_ref > 0)
	{
		if (--m_ref == 0)
		{	
			if (m_data_msg != NULL)
			{
				m_data_msg->Release();
			}
			m_data_msg = NULL;
			if (m_best_buffer != NULL)
			{
				DefaultMessagePool::ReleaseBestBuffer(m_best_buffer);
			}
			m_best_buffer = NULL;
			std::map<int, IBestField*>::iterator itor = m_best_field_map.begin();
			for (; itor != m_best_field_map.end(); ++itor)
			{
				DefaultMessagePool::ReleaseDefaultBestField((DefaultBestField*)itor->second);
			}
			m_best_field_map.clear();
			memset(&m_best_head_struct, 0, sizeof(BestHeadStruct));

			DefaultMessagePool::ReleaseDefaultBestHeadMessage(this);
			m_status = 0;
		}
	}
	return 0;
}

int32	DefaultBestHeadMessage::SetBuffer(const void* buffer, const int32& len)
{
	if (m_best_buffer != NULL)
	{
		DefaultMessagePool::ReleaseBestBuffer(m_best_buffer);
	}
	m_best_buffer = DefaultMessagePool::AcquireBestBuffer(len);
	m_best_buffer->len = len;
	memcpy(m_best_buffer->buff, buffer, len);	
	return 0;
}

///��ȡ��
void* DefaultBestHeadMessage::GetBuffer(int32* len)
{
	*len = m_best_buffer->len;
	return m_best_buffer->buff;
}

///���л�����
const void*  DefaultBestHeadMessage::Serialize(int32* len)
{
	if (m_best_buffer != NULL)
	{
		DefaultMessagePool::ReleaseBestBuffer(m_best_buffer);
	}
	IBestSerializer*  serializer = DefaultBestMessgeFactory::GetInstance()->GetSerializer(m_protocol_type);
	m_best_buffer = (BestBuffer*)serializer->SerializeHeadMessage(*len, this);
	m_best_head_struct.head_length = m_best_buffer->len;
	BestHeadStruct* headStruct = (BestHeadStruct*)m_best_buffer->buff;
	headStruct->head_length = m_best_buffer->len;
	m_status = 1;
	return m_best_buffer->buff;
}

int32 DefaultBestHeadMessage::Deserialize()
{
	//BestHeadStruct* bestHeadStruct = (BestHeadStruct*)m_best_buffer->buff;
	memcpy(&m_best_head_struct, m_best_buffer->buff, sizeof(BestHeadStruct));
	//int32 headLength = bestHeadStruct->head_length;
	DefaultBestSerializer*  serializer = DefaultBestSerializer::GetInstance();
	return serializer->DeserializeHeadMessage(this, m_best_buffer->buff, m_best_buffer->len);
}

IBestBase*  DefaultBestHeadMessage::AddRef(){
	++m_ref;
	return this;
}

//��ȡ��ǰ�ֶε�Э��
const PROTOCAL_TYPE DefaultBestHeadMessage::GetProtocal()
{
	return m_protocol_type;
}

int32  DefaultBestHeadMessage::SetProtocal(PROTOCAL_TYPE protpcal)
{
	m_protocol_type = protpcal;
	return 0;
}

int DefaultBestHeadMessage::ReleaseBuffer()
{
	if (m_best_buffer != NULL)
	{
		DefaultMessagePool::ReleaseBestBuffer(m_best_buffer);
		m_best_buffer = NULL;
	}
	return 0;
}