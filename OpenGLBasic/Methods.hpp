#pragma once
class Methods
{
public:
	Methods();
	~Methods();
	void beforeStratRendering();
	void render();
	void afterEndRendering();
	void key_callback(int key, int scancode, int action, int mode);
};

