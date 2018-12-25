
#include "default_best_rpchead.h"
#include "default_message_pool.h"

///��ȡЭ���ʶ��
int32  DefaultBestRPCHead::GetBestProtTag() 
{ 
	return m_best_rpc_struct.prot_tag;
}
///��ȡЭ���ʶ��
void  DefaultBestRPCHead::SetBestProtTag(const int32& prot_tag)
{
	m_best_rpc_struct.prot_tag = prot_tag;
}
///��ȡЭ��汾
int32  DefaultBestRPCHead::GetBestProtVersion()
{ 
	return m_best_rpc_struct.prot_version; 
}
///����Э��汾
void   DefaultBestRPCHead::SetBestProtVersion(const int32& prot_version)
{ 
	m_best_rpc_struct.prot_version = prot_version;
}
///��ȡЭ���ܳ���
uint32  DefaultBestRPCHead::GetTotalLenght()
{ 
	return m_best_rpc_struct.total_lenght;
}

void DefaultBestRPCHead::SetTotalLenght(int32 len)
{
	m_best_rpc_struct.total_lenght = len;
}
///��ȡ״̬��
uint8   DefaultBestRPCHead::GetStatus()
{ 
	return m_best_rpc_struct.status_code;
}
///����״̬��
void  DefaultBestRPCHead::SetStatus(const uint8& status)
{
	m_best_rpc_struct.status_code = status;
}
//��ȡ������
PACKET_TYPE  DefaultBestRPCHead::GetPackType()
{
	return (PACKET_TYPE)m_best_rpc_struct.type;
}
//���ð�����
void  DefaultBestRPCHead::SetPackType(const PACKET_TYPE& pack_type)
{
	m_best_rpc_struct.type = pack_type;
};
///��ȡ�Ӱ����� 
uint8  DefaultBestRPCHead::GetSubHeadNum()
{
	return m_best_rpc_struct.subnum;
}

void DefaultBestRPCHead::SetSubHeadNum(uint8 sub_num)
{
	m_best_rpc_struct.subnum = sub_num;
}
///��ȡ���к�
uint64  DefaultBestRPCHead::GetSeqNum()
{ 
	return m_best_rpc_struct.seq_num;
}
///�������к�
void   DefaultBestRPCHead::SetSeqNum(const uint64& seq_num)
{
	m_best_rpc_struct.seq_num = seq_num;
};

///��ȡ�Ự��
uint64  DefaultBestRPCHead::GetSessionNum()
{
	return m_best_rpc_struct.session_num;
}
///���ûỰ��
void   DefaultBestRPCHead::SetSessionNum(const uint64& session_num)
{
	m_best_rpc_struct.session_num = session_num;
}
///��ȡģ���
uint32  DefaultBestRPCHead::GetFuncNo()
{ 
	return m_best_rpc_struct.fun_no;
}
///����ģ���
void  DefaultBestRPCHead::SetFuncNo(const uint32& fun_no)
{
	m_best_rpc_struct.fun_no = fun_no;
};

///��ȡУ��λ
uint32 DefaultBestRPCHead::GetCRCCheck()
{
	return m_best_rpc_struct.crc_reserver;
}
///����У��λ
void  DefaultBestRPCHead::SetCRCCheck(const uint32& crc)
{
	m_best_rpc_struct.crc_reserver = crc;
}



///������
int32	DefaultBestRPCHead::SetBuffer(const void* buffer, const int32& len)
{ 
	if (len != sizeof(BestRpcStruct))return -1;
	BestRpcStruct* beststruct = (BestRpcStruct*)buffer;
	m_best_rpc_struct = *beststruct;
	return 0;
}
///��ȡ��
void* DefaultBestRPCHead::GetBuffer(int32* len)
{ 
	*len = sizeof(BestRpcStruct);
	return &m_best_rpc_struct;
}

///���л�����
const void*   DefaultBestRPCHead::Serialize(int32* len)
{
	*len = sizeof(m_best_rpc_struct);
	status = 1;
	return  &m_best_rpc_struct;
}
///�����л�
int32  DefaultBestRPCHead::Deserialize()
{

	status = 1;
	return 0;
}

///�������ü�������Ϊ0ʱ�ͷ�����
 uint64  DefaultBestRPCHead::Release(){
	 if (m_ref > 0)
	 {
		 if (--m_ref == 0)
		 {
			 DefaultMessagePool::ReleaseDefaultBestRPCHead(this);
		 }
	 }
	return 0;
}

IBestBase*  DefaultBestRPCHead::AddRef(){
	 ++m_ref;
	 if (m_ref == 1)
	 {
		 Reset();
	 }
	 return this;
 }

const PROTOCAL_TYPE DefaultBestRPCHead::GetProtocal()
{
	return m_protocol_type;
}

int32  DefaultBestRPCHead::SetProtocal(PROTOCAL_TYPE protpcal)
{
	m_protocol_type = protpcal;
	return 0;
}

void DefaultBestRPCHead::Reset()
{
	memset(&m_best_rpc_struct, 0, sizeof(BestRpcStruct));
	status = 0;
	m_best_rpc_struct.prot_tag = PROT_TAG;
	m_best_rpc_struct.prot_version = PROT_VERSION;
}

///����һ�������Ƶ�����
int32  DefaultBestRPCHead::CopyFrom(const IBestRPCHead *other)
{
	DefaultBestRPCHead* head = (DefaultBestRPCHead*)other;
	this->m_best_rpc_struct = head->m_best_rpc_struct;
	this->m_protocol_type = head->m_protocol_type;
	return 0;
}



///��������
DefaultBestRPCHead*  DefaultBestRPCHead::Clone()
{
	DefaultBestRPCHead* head = DefaultMessagePool::AcquireDefaultBestRPCHead();
	head->CopyFrom(this);
	return head;
}

