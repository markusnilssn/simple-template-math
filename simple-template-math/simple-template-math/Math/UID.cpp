#include "UID.h"

stm::UID::UID()
	: m_ID(0)
{

}

stm::UID::UID(const uint64_t aID)
	: m_ID(aID)
{

}

stm::UID::UID(const UID& other)
	: m_ID(other.m_ID)
{
}

stm::UID& stm::UID::operator=(const UID& other)
{
	m_ID = other.m_ID;
	return *this;
}

stm::UID::~UID()
{
}

const bool stm::UID::operator==(const UID& other) const
{
	return m_ID == other.m_ID;
}

const bool stm::UID::operator!=(const UID& other) const
{
	return m_ID != other.m_ID;
}

const bool stm::UID::IsNull() const
{
	return m_ID == 0;
}

stm::UID stm::UID::CreateUID()
{
	static unsigned int s_ID = 0;
	return UID(s_ID++);
}
