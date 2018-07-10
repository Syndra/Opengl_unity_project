#include "Mesh.h"
#include <stdio.h>
#include "Texture.h"

Mesh::Mesh(const char* meshName)
{
	init_mesh();

	char basicpath[200] = "obj/";

	strcat_s(basicpath, sizeof(basicpath), meshName);

	path = basicpath;

	loadAssimp();
}

Mesh::Mesh()
{
	init_mesh();

	path = "obj/sujan.obj";

	loadAssimp();
}


Mesh::~Mesh()
{
}

void Mesh::set_texture(const char * filepath)
{
	char basicpath[200] = "obj/";

	strcat_s(basicpath, sizeof(basicpath), filepath);

	Texture = Texture::CreateTexture(basicpath);
}

bool Mesh::loadAssimp()
{
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(path, 0/*aiProcess_JoinIdenticalVertices | aiProcess_SortByPType*/);
	if (!scene) {
		fprintf(stderr, importer.GetErrorString());
		getchar();
		return false;
	}
	const aiMesh* mesh = scene->mMeshes[0]; // In this simple example code we always use the 1rst mesh (in OBJ files there is often only one anyway)

											// Fill vertices positions
	vertices.reserve(mesh->mNumVertices);
	for (unsigned int i = 0; i<mesh->mNumVertices; i++) {
		aiVector3D pos = mesh->mVertices[i];
		vertices.push_back(glm::vec3(pos.x, pos.y, pos.z));
	}

	// Fill vertices texture coordinates
	uvs.reserve(mesh->mNumVertices);
	for (unsigned int i = 0; i<mesh->mNumVertices; i++) {
		aiVector3D UVW = mesh->mTextureCoords[0][i]; // Assume only 1 set of UV coords; AssImp supports 8 UV sets.
		uvs.push_back(glm::vec2(UVW.x, UVW.y));
	}

	// Fill vertices normals
	normals.reserve(mesh->mNumVertices);
	for (unsigned int i = 0; i<mesh->mNumVertices; i++) {
		aiVector3D n = mesh->mNormals[i];
		normals.push_back(glm::vec3(n.x, n.y, n.z));
	}


	// Fill face indices
	indices.reserve(3 * mesh->mNumFaces);
	for (unsigned int i = 0; i<mesh->mNumFaces; i++) {
		// Assume the model has only triangles.
		indices.push_back(mesh->mFaces[i].mIndices[0]);
		indices.push_back(mesh->mFaces[i].mIndices[1]);
		indices.push_back(mesh->mFaces[i].mIndices[2]);
	}
	
	// The "scene" pointer will be deleted automatically by "importer"
	return true;
}

void Mesh::init_mesh()
{
	indices = std::vector<unsigned short>();
	vertices = std::vector<glm::vec3>();
	uvs = std::vector<glm::vec2>();
	normals = std::vector<glm::vec3>();
}
