#include <stdint.h>

namespace stm
{
	class UID
	{
	public:
		UID();
		UID(const uint64_t aID);
		UID(const UID& other);
		UID& operator=(const UID& other);
		~UID();

		const bool operator==(const UID& other) const;
		const bool operator!=(const UID& other) const;

		const bool IsNull() const;

		static UID CreateUID();
	private:
		uint64_t m_ID;

	};
}