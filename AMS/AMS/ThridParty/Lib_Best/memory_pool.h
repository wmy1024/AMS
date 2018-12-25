// ΪQS����ƣ�����δʹ��
// ����������������£�Alloc/Free�ĺ�ʱֻ��new/delete��30%����
// ��CThreadMutex��֮�������δ��
#ifndef __MEMORY_POOL_H__
#define __MEMORY_POOL_H__

#include <vector>
using std::vector;
#include "best_message.h"
#include "qcstutils.h"

/// �ڴ����
/// �ʺ�Ƶ������/�ͷŹ̶�����С�ڴ�ĳ���
class MemoryPool
{
public:
    inline MemoryPool();
    inline ~MemoryPool();

    // ����0��ʾ�ɹ�
    // ����-1��ʾ�ڴ�����ʧ��
    // block_sizeΪ�ڴ���С
    // block_countΪ��ʼ�ڴ�����
    inline int Init(int block_size, int block_count);

    // �ӳ�����ȡ�ڴ��
    // ����NULL��ʾ�ڴ�����ʧ��
    inline uint8 * Alloc();
    // ���ڴ�黹��������
    inline void Free(void *block);

private:
    // ���ο������췽���͸�ֵ���������
    MemoryPool(const MemoryPool &another);
    MemoryPool & operator = (const MemoryPool &another);

private:
    // ��һ���ڴ��ĵ�ַ
    uint8 *m_head;

    // ��ʼ��ʱÿ���ڴ�Ĵ�С
    int m_block_size;
    // ��ʼ��ʱ�ڴ��ĸ���
    int m_block_count;

    // ���ڴ�ŴӲ���ϵͳ��ȡ���ڴ��׵�ַ
    vector<uint8 *> m_start_address;

    // ��������֤���̷߳��ʰ�ȫ
    QCMutex m_mutex;
};

#include "memory_pool.inl"

#endif
