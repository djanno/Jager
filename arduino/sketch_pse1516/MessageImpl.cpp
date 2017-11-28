#include "MessageImpl.h"

MessageImpl::MessageImpl(Content content) {
	this->content = content;
}

Content MessageImpl::getContent() const {
	return this->content;
}