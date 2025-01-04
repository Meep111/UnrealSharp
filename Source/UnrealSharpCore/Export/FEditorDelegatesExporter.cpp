#include "FEditorDelegatesExporter.h"

void UFEditorDelegatesExporter::ExportFunctions(FRegisterExportedFunction RegisterExportedFunction)
{
#if WITH_EDITOR
	EXPORT_FUNCTION(BindEndPIE)
	EXPORT_FUNCTION(BindStartPIE)
	EXPORT_FUNCTION(UnbindEndPIE)
	EXPORT_FUNCTION(UnbindStartPIE)
#endif
}

void UFEditorDelegatesExporter::BindEndPIE(FPIEEvent Delegate, FDelegateHandle& DelegateHandle)
{
#if WITH_EDITOR
	DelegateHandle = FEditorDelegates::EndPIE.AddLambda(Delegate);
#endif
}

void UFEditorDelegatesExporter::BindStartPIE(FPIEEvent Delegate, FDelegateHandle& DelegateHandle)
{
#if WITH_EDITOR
	DelegateHandle = FEditorDelegates::BeginPIE.AddLambda(Delegate);
#endif
}

void UFEditorDelegatesExporter::UnbindStartPIE(FDelegateHandle DelegateHandle)
{
#if WITH_EDITOR
	FEditorDelegates::BeginPIE.Remove(DelegateHandle);
#endif
}

void UFEditorDelegatesExporter::UnbindEndPIE(FDelegateHandle DelegateHandle)
{
#if WITH_EDITOR
	FEditorDelegates::EndPIE.Remove(DelegateHandle);
#endif
}
