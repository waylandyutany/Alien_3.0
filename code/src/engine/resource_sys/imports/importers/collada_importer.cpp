#include "StdAfx.h"

#include "collada_importer.h"

#include "collada/collada_mesh_importer.h"
#include "collada/mesh_exporter.h"

#include "../../resources/resources_manager.h"

#include "../../../base_sys/memory/allocators/incremental_allocator.h"
#include "../../../base_sys/file_system/file_system.h"
#include "../../../debug_sys/output/outputs.h"
#include "../../../debug_sys/profiler/profiler.h"

namespace ae { namespace resource {

C_ColladaImporter::C_ColladaImporter()
{
}

bool C_ColladaImporter::Import(const char* fileToImport, const char* resourceToExport, const ae::base::S_XMLNode*)
{
	ae::base::C_FileSys& fileSys(ae::base::C_FileSys::Inst());
	ae::base::C_FileSys::S_MappedFile* pMappedFile = fileSys.OpenMappedFile(fileToImport);
	if(!pMappedFile) return false;
// *****************************************************************************************************
	const size_t fileSize(fileSys.GetFileSize(fileToImport));
	char* pMemBuffer = static_cast<char*>(::malloc(fileSize));
	ae::base::C_IncrementalAllocator allocator;
	allocator.Create(pMemBuffer, fileSize);
	allocator.Reset(true);
// *****************************************************************************************************
//	PROFILE_BLOCK_BEGIN(Import);
	ae::resource::C_ColladaParser::T_FileInputStream m_Input(pMappedFile->Buffer<char*>(), pMappedFile->Buffer<char*>() + pMappedFile->Size());
	ae::resource::C_ColladaMeshImporter meshImporter(m_Input, allocator);
//	PROFILE_BLOCK_END(Import);
//	DBG_OUT << Import;
//	meshImporter.PrintDebug();
// *****************************************************************************************************
//	PROFILE_BLOCK_BEGIN(Export);
	ae::resource::C_Mesh_Exporter meshExporter(resourceToExport, meshImporter, 0, false, false);
//	C_ResourceLoader::Inst().PrintDebugInfo(pMemBuffer1, m_Allocator1.GetUsage());
//	PROFILE_BLOCK_END(Export);
//	DBG_OUT << Export;
// *****************************************************************************************************
	::free(allocator.GetBottomPointer());
	fileSys.CloseMappedFile(pMappedFile);
	return true;
}

} } // namespace ae { namespace resource {
