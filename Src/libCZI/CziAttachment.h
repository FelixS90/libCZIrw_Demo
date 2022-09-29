
#pragma once

#include "libCZI.h"
#include "CziParse.h"

class CCziAttachment : public  libCZI::IAttachment
{
private:
	std::shared_ptr<const void> spData;
	std::uint64_t	dataSize;
	libCZI::AttachmentInfo	info;
public:
	CCziAttachment(const libCZI::AttachmentInfo& info, const CCZIParse::AttachmentData& data, std::function<void(void*)> deleter);
	virtual ~CCziAttachment();

	// interface IAttachment
	const libCZI::AttachmentInfo& GetAttachmentInfo() const override;

	void DangerousGetRawData(const void*& ptr, size_t& size) const override;

	std::shared_ptr<const void> GetRawData(size_t* ptrSize) override;
};
