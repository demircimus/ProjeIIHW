//
//  SimpleEffect.h
//  Ders 7
//
//  Created by Gurel Erceis on 4/15/13.
//  Copyright (c) 2013 Yogurt3D. All rights reserved.
//

#ifndef Ders_7_SimpleEffect_h
#define Ders_7_SimpleEffect_h
#include "Effect.h"

class SimpleEffect: public Effect{
public:
    SimpleEffect(int* screen_width, int* screen_height):Effect("effect_simple.frag",screen_width, screen_height){
        
    }
    virtual void draw(){
        glUseProgram(programID);
		generateImages("gradient.jpg", "alexDeSouza.jpg");
        Effect::draw();
    }

	void generateImages(char * rampimage, char * mainImage)
	{
		glActiveTexture(GL_TEXTURE2);
		LoadGLTexture(rampimage, 800, 600);
		glUniform1i(rampImage, 2);

		glActiveTexture(GL_TEXTURE0);
		LoadGLTexture(mainImage, 800, 600);
        glUniform1i(UniformTexture, /*GL_TEXTURE*/0);
	}
private:
    GLuint UniformOffset;
};

#endif
