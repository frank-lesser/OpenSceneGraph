#include <osg/TexEnvCombine>
#include <osg/GLExtensions>

using namespace osg;

TexEnvCombine::TexEnvCombine()
{
    _constantColor.set(0.0f,0.0f,0.0f,0.0f);
}


TexEnvCombine::~TexEnvCombine()
{
}

void TexEnvCombine::apply(State&) const
{
    static bool isTexEnvCombineSupported =
        isGLExtensionSupported("GL_ARB_texture_env_combine");

    if (isTexEnvCombineSupported)
    {
        glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_ARB);

        glTexEnvi( GL_TEXTURE_ENV, GL_COMBINE_RGB_ARB, _combine_RGB);
        glTexEnvi( GL_TEXTURE_ENV, GL_COMBINE_ALPHA_ARB, _combine_Alpha);

        glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE0_RGB_ARB,_source0_RGB );
        glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE1_RGB_ARB, _source1_RGB);
        glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE2_RGB_ARB,_source2_RGB );

        glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE0_ALPHA_ARB, _source0_Alpha);
        glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE1_ALPHA_ARB, _source1_Alpha);
        glTexEnvi( GL_TEXTURE_ENV, GL_SOURCE2_ALPHA_ARB, _source2_Alpha);

        glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND0_RGB_ARB, _operand0_RGB);
        glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND1_RGB_ARB, _operand1_RGB);
        glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND2_RGB_ARB, _operand2_RGB);

        glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND0_ALPHA_ARB, _operand0_Alpha);
        glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND1_ALPHA_ARB, _operand1_Alpha);
        glTexEnvi( GL_TEXTURE_ENV, GL_OPERAND2_ALPHA_ARB, _operand2_Alpha);

        glTexEnvf( GL_TEXTURE_ENV, GL_RGB_SCALE_ARB, _scale_RGB);
        glTexEnvf( GL_TEXTURE_ENV, GL_ALPHA_SCALE, _scale_Alpha);

        glTexEnvfv( GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, _constantColor.ptr());
    }
    else
    {
        // what is the best fallback when the tex env combine is not supported??
        // we will resort the settung the OpenGL default of GL_MODULATE.
        glTexEnvi( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    }
}
