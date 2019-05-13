#include "commonLib.h"

using namespace std;
int main()
{
	//Variable.
	int frame = 0, time, timebase = 0;
	GLuint frame_period;

	//setting
	//initialize GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	GLFWwindow *window = glfwCreateWindow(640, 480, "My title", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "F fuck u\n");
		std::cout << "???";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true;

	if (glewInit() != GLEW_OK) {
		std::cout << "???!";
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	//Init Shader program
	GLuint programID = LoadShaders("SimpleVertexShader.txt", "SimpleFragmentShader.txt");

	//Setting properties.
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//Init VAO
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	//Initialize Buffer.
	GLuint vertex_buffer;
	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex_data::tri_data), Vertex_data::tri_data, GL_STATIC_DRAW);
	 
	GLuint color_buffer;
	glGenBuffers(1, &color_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, color_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex_data::color), Vertex_data::color, GL_STATIC_DRAW);

	GLuint texturecoordinate_buffer;
	glGenBuffers(1, &texturecoordinate_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, texturecoordinate_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex_data::textureCoordinate), Vertex_data::textureCoordinate, GL_STATIC_DRAW);

	//load image to texture
	GLuint textureid = CreateTexture("number-board.jpg");
	glUniform1i(glGetUniformLocation(programID, "tex"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureid);

	//mvp matrix
	//proj
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)4 / (float)3, 0.1f, 100.0f);
	glm::mat4 View = glm::lookAt(glm::vec3(0, 0, 6), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::mat4 Model = glm::mat4(1.0f);
	glm::mat4 mvp = Projection * View * Model;

	//Get current buffer Matrix Id.
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

	//main loop
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	do {
		//Get frame count
		time = glfwGetTime();
		GLfloat deltatime = time - timebase;
		timebase = time;
		std::cout << time;

		//use shader.
		glUseProgram(programID);

		//set default background color.
		glClearColor(0, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//set Attribute buffer - vertex for triangle.
		GLuint vertex_attribute = glGetAttribLocation(programID, "vertex_attribute");
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
		glVertexAttribPointer(
			vertex_attribute,   // attribute 0. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		glEnableVertexAttribArray(vertex_attribute);
	
		//set Color Attribute buffer - color for triangle.
		GLuint color_attribute = glGetAttribLocation(programID, "color_attribute");
		glBindBuffer(GL_ARRAY_BUFFER, color_buffer);
		glVertexAttribPointer(
			color_attribute,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);
		glEnableVertexAttribArray(color_attribute);
		
		//set texture Attribute buffer - texture for triangle.
		GLint texturecoordinate_attribute = glGetAttribLocation(programID, "uv_attribute");
		if (texturecoordinate_attribute == -1) {
			cerr << "Texture Coord inate 속성 설정 실패" << endl;
			return false;
		}
		glBindBuffer(GL_ARRAY_BUFFER, texturecoordinate_buffer);
		glVertexAttribPointer(
			texturecoordinate_attribute,
			2,
			GL_FLOAT,
			GL_FALSE,
			0,
			0
		);
		glEnableVertexAttribArray(texturecoordinate_attribute);

		//Handle Event.
		//glm::mat4 ViewMatrix = control::get_view_matrix(window, deltatime);
		//View *= ViewMatrix;
		//glm::mat4 mvp = Projection * View * Model;

		//Do mvp matrix multiplication.
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

		//Draw in window.
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();


	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);	
}