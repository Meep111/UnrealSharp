﻿#pragma once

#include "CoreMinimal.h"
#include "FunctionsExporter.h"
#include "FQuatExporter.generated.h"

UCLASS(meta = (NotGeneratorValid))
class UNREALSHARPCORE_API UFQuatExporter : public UFunctionsExporter
{
	GENERATED_BODY()

public:

	// UFunctions interface implementation
	virtual void ExportFunctions(FRegisterExportedFunction RegisterExportedFunction) override;
	// End

private:

	static void ToQuaternion(FQuat& Quaternion, const FRotator& Rotator);
	static void ToRotator(FRotator& Rotator, const FQuat& Quaternion);
	
};
