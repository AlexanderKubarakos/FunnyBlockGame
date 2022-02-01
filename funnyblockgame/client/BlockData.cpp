#include "BlockData.h"

namespace client
{
	BlockData::BlockData(const char* name, bool makeFullyTransparent)
	{
		//, const char* resourceLocation
		this->name = name;

		// TODO: this is temp
		model.setModelToBlockModel();
	}

	std::string BlockData::getName()
	{
		return name;
	}

	Model& BlockData::getModel()
	{
		return model;
	}
}