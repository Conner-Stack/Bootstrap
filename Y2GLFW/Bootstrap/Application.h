#pragma once
struct GLFWwindow;

class Application
{
public:
	Application();
	virtual ~Application();
	void run(const char* title, unsigned int width, unsigned int height, bool fullscreen);
protected:
	virtual void shartup() = 0;
	virtual void shudown() = 0;
	virtual void update(float) = 0;
	virtual void draw() = 0;
	GLFWwindow *m_window;
	bool gameOver;
};

