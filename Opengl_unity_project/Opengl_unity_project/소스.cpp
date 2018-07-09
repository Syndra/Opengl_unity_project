//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>
//
//struct Vertex
//{
//	glm::vec3 position;
//	glm::vec3 normal;
//};
//
//struct Mesh
//{
//	//The vertex array object, vertex buffer object and element buffer object
//	GLuint VAO;
//	GLuint VBO;
//	GLuint EBO;
//	//Vectors for the vertices and indices to put in the buffers
//	std::vector<Vertex> vertices;
//	std::vector<GLuint> indices;
//
//	//Constructor
//	Mesh(const std::vector<Vertex>& vertices, const std::vector<GLuint>& indices)
//	{
//		this->vertices = vertices;
//		this->indices = indices;
//
//		//Generate the VAO
//		glGenVertexArrays(1, &VAO);
//
//		//Generate the buffer objects
//		glGenBuffers(1, &VBO);
//		glGenBuffers(1, &EBO);
//
//		//Bind the VAO
//		glBindVertexArray(VAO);
//
//		//Bind the VBO and set the vertices
//		glBindBuffer(GL_ARRAY_BUFFER, VBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices.at(0), GL_STATIC_DRAW);
//
//		//Enable the first attribute pointer
//		glEnableVertexAttribArray(0);
//		//Set the attribute pointer    The stride is meant to be 'sizeof(Vertex)', but it doesn't work at all that way
//		//                                              \/
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//		//Enable the second attribute pointer
//		glEnableVertexAttribArray(1);
//		//Set the attribute pointer                   ditto
//		//                                              \/
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)offsetof(Vertex, normal));
//
//		//Bind the EBO and set the indices
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices.at(0), GL_STATIC_DRAW);
//
//		//Report any errors
//		GLenum error = glGetError();
//		if (error != GL_NO_ERROR)
//		{
//			std::cerr << "Error while creating mesh!" << std::endl;
//		}
//
//		glBindVertexArray(0);
//	}
//
//	void draw()
//	{
//		//Bind the VAO
//		glBindVertexArray(VAO);
//
//		//Bind the ELement Buffer Object
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//
//		//Draw the mesh
//		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
//
//		//Unbind the VAO
//		glBindVertexArray(0);
//	}
//};
//
//int main()
//{
//	//Intialize GLFW (no error checking for brevity)
//	glfwInit();
//
//	//Set the OpenGL version to 3.3
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	//Create a new window
//	GLFWwindow* window = glfwCreateWindow(800, 600, "Model Testing", NULL, NULL);
//
//	glfwMakeContextCurrent(window);
//
//	//Initialize glew (no checking again)
//	glewInit();
//
//	glViewport(0, 0, 800, 600);
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//
//	//Load the model
//	Assimp::Importer importer;
//	const aiScene* scene = importer.ReadFile("mymodel.obj", aiProcess_Triangulate | aiProcess_GenNormals);
//
//	//Check for errors
//	if ((!scene) || (scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE) || (!scene->mRootNode))
//	{
//		std::cerr << "Error loading mymodel.obj: " << std::string(importer.GetErrorString()) << std::endl;
//		//Return fail
//		return -1;
//	}
//
//	//A vector to store the meshes
//	std::vector<std::unique_ptr<Mesh> > meshes;
//	//Iterate over the meshes
//	for (unsigned int i = 0; i < scene->mNumMeshes; ++i)
//	{
//		//Get the mesh
//		aiMesh* mesh = scene->mMeshes[i];
//
//		//Create vectors for the vertices and indices
//		std::vector<Vertex> vertices;
//		std::vector<GLuint> indices;
//
//		//Iterate over the vertices of the mesh
//		for (unsigned int j = 0; j < mesh->mNumVertices; ++j)
//		{
//			//Create a vertex to store the mesh's vertices temporarily
//			Vertex tempVertex;
//
//			//Set the positions
//			tempVertex.position.x = mesh->mVertices[j].x;
//			tempVertex.position.y = mesh->mVertices[j].y;
//			tempVertex.position.z = mesh->mVertices[j].z;
//
//			//Set the normals
//			tempVertex.normal.x = mesh->mNormals[j].x;
//			tempVertex.normal.y = mesh->mNormals[j].y;
//			tempVertex.normal.z = mesh->mNormals[j].z;
//
//			//Add the vertex to the vertices vector
//			vertices.push_back(tempVertex);
//		}
//
//		//Iterate over the faces of the mesh
//		for (unsigned int j = 0; j < mesh->mNumFaces; ++j)
//		{
//			//Get the face
//			aiFace face = mesh->mFaces[j];
//			//Add the indices of the face to the vector
//			for (unsigned int k = 0; k < face.mNumIndices; ++k) { indices.push_back(face.mIndices[k]); }
//		}
//
//		//Create a new mesh and add it to the vector
//		meshes.push_back(std::unique_ptr<Mesh>(new Mesh(std::move(vertices), std::move(indices))));
//	}
//
//	//While the window shouldn't be closed
//	while (!glfwWindowShouldClose(window))
//	{
//		//Clear the buffer
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		//Draw all the meshes
//		for (auto& mesh : meshes) { mesh.get()->draw(); }
//
//		//Swap the buffers
//		glfwSwapBuffers(window);
//	}
//
//	//Close the window now that it's not needed anymore
//	glfwDestroyWindow(window);
//
//	return 0;
//}