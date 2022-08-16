#pragma once



#define GLFUNCS \
x(void, glDrawRangeElements, PFNGLDRAWRANGEELEMENTSPROC, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) \
x(void, glTexImage3D, PFNGLTEXIMAGE3DPROC, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glTexSubImage3D, PFNGLTEXSUBIMAGE3DPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) \
x(void, glCopyTexSubImage3D, PFNGLCOPYTEXSUBIMAGE3DPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glActiveTexture, PFNGLACTIVETEXTUREPROC, GLenum texture) \
x(void, glSampleCoverage, PFNGLSAMPLECOVERAGEPROC, GLfloat value, GLboolean invert) \
x(void, glCompressedTexImage3D, PFNGLCOMPRESSEDTEXIMAGE3DPROC, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) \
x(void, glCompressedTexImage2D, PFNGLCOMPRESSEDTEXIMAGE2DPROC, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) \
x(void, glCompressedTexImage1D, PFNGLCOMPRESSEDTEXIMAGE1DPROC, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) \
x(void, glCompressedTexSubImage3D, PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) \
x(void, glCompressedTexSubImage2D, PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) \
x(void, glCompressedTexSubImage1D, PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) \
x(void, glGetCompressedTexImage, PFNGLGETCOMPRESSEDTEXIMAGEPROC, GLenum target, GLint level, void *img) \
x(void, glClientActiveTexture, PFNGLCLIENTACTIVETEXTUREPROC, GLenum texture) \
x(void, glMultiTexCoord1d, PFNGLMULTITEXCOORD1DPROC, GLenum target, GLdouble s) \
x(void, glMultiTexCoord1dv, PFNGLMULTITEXCOORD1DVPROC, GLenum target, const GLdouble *v) \
x(void, glMultiTexCoord1f, PFNGLMULTITEXCOORD1FPROC, GLenum target, GLfloat s) \
x(void, glMultiTexCoord1fv, PFNGLMULTITEXCOORD1FVPROC, GLenum target, const GLfloat *v) \
x(void, glMultiTexCoord1i, PFNGLMULTITEXCOORD1IPROC, GLenum target, GLint s) \
x(void, glMultiTexCoord1iv, PFNGLMULTITEXCOORD1IVPROC, GLenum target, const GLint *v) \
x(void, glMultiTexCoord1s, PFNGLMULTITEXCOORD1SPROC, GLenum target, GLshort s) \
x(void, glMultiTexCoord1sv, PFNGLMULTITEXCOORD1SVPROC, GLenum target, const GLshort *v) \
x(void, glMultiTexCoord2d, PFNGLMULTITEXCOORD2DPROC, GLenum target, GLdouble s, GLdouble t) \
x(void, glMultiTexCoord2dv, PFNGLMULTITEXCOORD2DVPROC, GLenum target, const GLdouble *v) \
x(void, glMultiTexCoord2f, PFNGLMULTITEXCOORD2FPROC, GLenum target, GLfloat s, GLfloat t) \
x(void, glMultiTexCoord2fv, PFNGLMULTITEXCOORD2FVPROC, GLenum target, const GLfloat *v) \
x(void, glMultiTexCoord2i, PFNGLMULTITEXCOORD2IPROC, GLenum target, GLint s, GLint t) \
x(void, glMultiTexCoord2iv, PFNGLMULTITEXCOORD2IVPROC, GLenum target, const GLint *v) \
x(void, glMultiTexCoord2s, PFNGLMULTITEXCOORD2SPROC, GLenum target, GLshort s, GLshort t) \
x(void, glMultiTexCoord2sv, PFNGLMULTITEXCOORD2SVPROC, GLenum target, const GLshort *v) \
x(void, glMultiTexCoord3d, PFNGLMULTITEXCOORD3DPROC, GLenum target, GLdouble s, GLdouble t, GLdouble r) \
x(void, glMultiTexCoord3dv, PFNGLMULTITEXCOORD3DVPROC, GLenum target, const GLdouble *v) \
x(void, glMultiTexCoord3f, PFNGLMULTITEXCOORD3FPROC, GLenum target, GLfloat s, GLfloat t, GLfloat r) \
x(void, glMultiTexCoord3fv, PFNGLMULTITEXCOORD3FVPROC, GLenum target, const GLfloat *v) \
x(void, glMultiTexCoord3i, PFNGLMULTITEXCOORD3IPROC, GLenum target, GLint s, GLint t, GLint r) \
x(void, glMultiTexCoord3iv, PFNGLMULTITEXCOORD3IVPROC, GLenum target, const GLint *v) \
x(void, glMultiTexCoord3s, PFNGLMULTITEXCOORD3SPROC, GLenum target, GLshort s, GLshort t, GLshort r) \
x(void, glMultiTexCoord3sv, PFNGLMULTITEXCOORD3SVPROC, GLenum target, const GLshort *v) \
x(void, glMultiTexCoord4d, PFNGLMULTITEXCOORD4DPROC, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) \
x(void, glMultiTexCoord4dv, PFNGLMULTITEXCOORD4DVPROC, GLenum target, const GLdouble *v) \
x(void, glMultiTexCoord4f, PFNGLMULTITEXCOORD4FPROC, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) \
x(void, glMultiTexCoord4fv, PFNGLMULTITEXCOORD4FVPROC, GLenum target, const GLfloat *v) \
x(void, glMultiTexCoord4i, PFNGLMULTITEXCOORD4IPROC, GLenum target, GLint s, GLint t, GLint r, GLint q) \
x(void, glMultiTexCoord4iv, PFNGLMULTITEXCOORD4IVPROC, GLenum target, const GLint *v) \
x(void, glMultiTexCoord4s, PFNGLMULTITEXCOORD4SPROC, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) \
x(void, glMultiTexCoord4sv, PFNGLMULTITEXCOORD4SVPROC, GLenum target, const GLshort *v) \
x(void, glLoadTransposeMatrixf, PFNGLLOADTRANSPOSEMATRIXFPROC, const GLfloat *m) \
x(void, glLoadTransposeMatrixd, PFNGLLOADTRANSPOSEMATRIXDPROC, const GLdouble *m) \
x(void, glMultTransposeMatrixf, PFNGLMULTTRANSPOSEMATRIXFPROC, const GLfloat *m) \
x(void, glMultTransposeMatrixd, PFNGLMULTTRANSPOSEMATRIXDPROC, const GLdouble *m) \
x(void, glBlendFuncSeparate, PFNGLBLENDFUNCSEPARATEPROC, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) \
x(void, glMultiDrawArrays, PFNGLMULTIDRAWARRAYSPROC, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount) \
x(void, glMultiDrawElements, PFNGLMULTIDRAWELEMENTSPROC, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount) \
x(void, glPointParameterf, PFNGLPOINTPARAMETERFPROC, GLenum pname, GLfloat param) \
x(void, glPointParameterfv, PFNGLPOINTPARAMETERFVPROC, GLenum pname, const GLfloat *params) \
x(void, glPointParameteri, PFNGLPOINTPARAMETERIPROC, GLenum pname, GLint param) \
x(void, glPointParameteriv, PFNGLPOINTPARAMETERIVPROC, GLenum pname, const GLint *params) \
x(void, glFogCoordf, PFNGLFOGCOORDFPROC, GLfloat coord) \
x(void, glFogCoordfv, PFNGLFOGCOORDFVPROC, const GLfloat *coord) \
x(void, glFogCoordd, PFNGLFOGCOORDDPROC, GLdouble coord) \
x(void, glFogCoorddv, PFNGLFOGCOORDDVPROC, const GLdouble *coord) \
x(void, glFogCoordPointer, PFNGLFOGCOORDPOINTERPROC, GLenum type, GLsizei stride, const void *pointer) \
x(void, glSecondaryColor3b, PFNGLSECONDARYCOLOR3BPROC, GLbyte red, GLbyte green, GLbyte blue) \
x(void, glSecondaryColor3bv, PFNGLSECONDARYCOLOR3BVPROC, const GLbyte *v) \
x(void, glSecondaryColor3d, PFNGLSECONDARYCOLOR3DPROC, GLdouble red, GLdouble green, GLdouble blue) \
x(void, glSecondaryColor3dv, PFNGLSECONDARYCOLOR3DVPROC, const GLdouble *v) \
x(void, glSecondaryColor3f, PFNGLSECONDARYCOLOR3FPROC, GLfloat red, GLfloat green, GLfloat blue) \
x(void, glSecondaryColor3fv, PFNGLSECONDARYCOLOR3FVPROC, const GLfloat *v) \
x(void, glSecondaryColor3i, PFNGLSECONDARYCOLOR3IPROC, GLint red, GLint green, GLint blue) \
x(void, glSecondaryColor3iv, PFNGLSECONDARYCOLOR3IVPROC, const GLint *v) \
x(void, glSecondaryColor3s, PFNGLSECONDARYCOLOR3SPROC, GLshort red, GLshort green, GLshort blue) \
x(void, glSecondaryColor3sv, PFNGLSECONDARYCOLOR3SVPROC, const GLshort *v) \
x(void, glSecondaryColor3ub, PFNGLSECONDARYCOLOR3UBPROC, GLubyte red, GLubyte green, GLubyte blue) \
x(void, glSecondaryColor3ubv, PFNGLSECONDARYCOLOR3UBVPROC, const GLubyte *v) \
x(void, glSecondaryColor3ui, PFNGLSECONDARYCOLOR3UIPROC, GLuint red, GLuint green, GLuint blue) \
x(void, glSecondaryColor3uiv, PFNGLSECONDARYCOLOR3UIVPROC, const GLuint *v) \
x(void, glSecondaryColor3us, PFNGLSECONDARYCOLOR3USPROC, GLushort red, GLushort green, GLushort blue) \
x(void, glSecondaryColor3usv, PFNGLSECONDARYCOLOR3USVPROC, const GLushort *v) \
x(void, glSecondaryColorPointer, PFNGLSECONDARYCOLORPOINTERPROC, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glWindowPos2d, PFNGLWINDOWPOS2DPROC, GLdouble x, GLdouble y) \
x(void, glWindowPos2dv, PFNGLWINDOWPOS2DVPROC, const GLdouble *v) \
x(void, glWindowPos2f, PFNGLWINDOWPOS2FPROC, GLfloat x, GLfloat y) \
x(void, glWindowPos2fv, PFNGLWINDOWPOS2FVPROC, const GLfloat *v) \
x(void, glWindowPos2i, PFNGLWINDOWPOS2IPROC, GLint x, GLint y) \
x(void, glWindowPos2iv, PFNGLWINDOWPOS2IVPROC, const GLint *v) \
x(void, glWindowPos2s, PFNGLWINDOWPOS2SPROC, GLshort x, GLshort y) \
x(void, glWindowPos2sv, PFNGLWINDOWPOS2SVPROC, const GLshort *v) \
x(void, glWindowPos3d, PFNGLWINDOWPOS3DPROC, GLdouble x, GLdouble y, GLdouble z) \
x(void, glWindowPos3dv, PFNGLWINDOWPOS3DVPROC, const GLdouble *v) \
x(void, glWindowPos3f, PFNGLWINDOWPOS3FPROC, GLfloat x, GLfloat y, GLfloat z) \
x(void, glWindowPos3fv, PFNGLWINDOWPOS3FVPROC, const GLfloat *v) \
x(void, glWindowPos3i, PFNGLWINDOWPOS3IPROC, GLint x, GLint y, GLint z) \
x(void, glWindowPos3iv, PFNGLWINDOWPOS3IVPROC, const GLint *v) \
x(void, glWindowPos3s, PFNGLWINDOWPOS3SPROC, GLshort x, GLshort y, GLshort z) \
x(void, glWindowPos3sv, PFNGLWINDOWPOS3SVPROC, const GLshort *v) \
x(void, glBlendColor, PFNGLBLENDCOLORPROC, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) \
x(void, glBlendEquation, PFNGLBLENDEQUATIONPROC, GLenum mode) \
x(void, glGenQueries, PFNGLGENQUERIESPROC, GLsizei n, GLuint *ids) \
x(void, glDeleteQueries, PFNGLDELETEQUERIESPROC, GLsizei n, const GLuint *ids) \
x(GLboolean, glIsQuery, PFNGLISQUERYPROC, GLuint id) \
x(void, glBeginQuery, PFNGLBEGINQUERYPROC, GLenum target, GLuint id) \
x(void, glEndQuery, PFNGLENDQUERYPROC, GLenum target) \
x(void, glGetQueryiv, PFNGLGETQUERYIVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetQueryObjectiv, PFNGLGETQUERYOBJECTIVPROC, GLuint id, GLenum pname, GLint *params) \
x(void, glGetQueryObjectuiv, PFNGLGETQUERYOBJECTUIVPROC, GLuint id, GLenum pname, GLuint *params) \
x(void, glBindBuffer, PFNGLBINDBUFFERPROC, GLenum target, GLuint buffer) \
x(void, glDeleteBuffers, PFNGLDELETEBUFFERSPROC, GLsizei n, const GLuint *buffers) \
x(void, glGenBuffers, PFNGLGENBUFFERSPROC, GLsizei n, GLuint *buffers) \
x(GLboolean, glIsBuffer, PFNGLISBUFFERPROC, GLuint buffer) \
x(void, glBufferData, PFNGLBUFFERDATAPROC, GLenum target, GLsizeiptr size, const void *data, GLenum usage) \
x(void, glBufferSubData, PFNGLBUFFERSUBDATAPROC, GLenum target, GLintptr offset, GLsizeiptr size, const void *data) \
x(void, glGetBufferSubData, PFNGLGETBUFFERSUBDATAPROC, GLenum target, GLintptr offset, GLsizeiptr size, void *data) \
x(GLboolean, glUnmapBuffer, PFNGLUNMAPBUFFERPROC, GLenum target) \
x(void, glGetBufferParameteriv, PFNGLGETBUFFERPARAMETERIVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetBufferPointerv, PFNGLGETBUFFERPOINTERVPROC, GLenum target, GLenum pname, void **params) \
x(void, glBlendEquationSeparate, PFNGLBLENDEQUATIONSEPARATEPROC, GLenum modeRGB, GLenum modeAlpha) \
x(void, glDrawBuffers, PFNGLDRAWBUFFERSPROC, GLsizei n, const GLenum *bufs) \
x(void, glStencilOpSeparate, PFNGLSTENCILOPSEPARATEPROC, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) \
x(void, glStencilFuncSeparate, PFNGLSTENCILFUNCSEPARATEPROC, GLenum face, GLenum func, GLint ref, GLuint mask) \
x(void, glStencilMaskSeparate, PFNGLSTENCILMASKSEPARATEPROC, GLenum face, GLuint mask) \
x(void, glAttachShader, PFNGLATTACHSHADERPROC, GLuint program, GLuint shader) \
x(void, glBindAttribLocation, PFNGLBINDATTRIBLOCATIONPROC, GLuint program, GLuint index, const GLchar *name) \
x(void, glCompileShader, PFNGLCOMPILESHADERPROC, GLuint shader) \
x(GLuint, glCreateProgram, PFNGLCREATEPROGRAMPROC, void) \
x(GLuint, glCreateShader, PFNGLCREATESHADERPROC, GLenum type) \
x(void, glDeleteProgram, PFNGLDELETEPROGRAMPROC, GLuint program) \
x(void, glDeleteShader, PFNGLDELETESHADERPROC, GLuint shader) \
x(void, glDetachShader, PFNGLDETACHSHADERPROC, GLuint program, GLuint shader) \
x(void, glDisableVertexAttribArray, PFNGLDISABLEVERTEXATTRIBARRAYPROC, GLuint index) \
x(void, glEnableVertexAttribArray, PFNGLENABLEVERTEXATTRIBARRAYPROC, GLuint index) \
x(void, glGetActiveAttrib, PFNGLGETACTIVEATTRIBPROC, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) \
x(void, glGetActiveUniform, PFNGLGETACTIVEUNIFORMPROC, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name) \
x(void, glGetAttachedShaders, PFNGLGETATTACHEDSHADERSPROC, GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders) \
x(GLint, glGetAttribLocation, PFNGLGETATTRIBLOCATIONPROC, GLuint program, const GLchar *name) \
x(void, glGetProgramiv, PFNGLGETPROGRAMIVPROC, GLuint program, GLenum pname, GLint *params) \
x(void, glGetProgramInfoLog, PFNGLGETPROGRAMINFOLOGPROC, GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) \
x(void, glGetShaderiv, PFNGLGETSHADERIVPROC, GLuint shader, GLenum pname, GLint *params) \
x(void, glGetShaderInfoLog, PFNGLGETSHADERINFOLOGPROC, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) \
x(void, glGetShaderSource, PFNGLGETSHADERSOURCEPROC, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source) \
x(GLint, glGetUniformLocation, PFNGLGETUNIFORMLOCATIONPROC, GLuint program, const GLchar *name) \
x(void, glGetUniformfv, PFNGLGETUNIFORMFVPROC, GLuint program, GLint location, GLfloat *params) \
x(void, glGetUniformiv, PFNGLGETUNIFORMIVPROC, GLuint program, GLint location, GLint *params) \
x(void, glGetVertexAttribdv, PFNGLGETVERTEXATTRIBDVPROC, GLuint index, GLenum pname, GLdouble *params) \
x(void, glGetVertexAttribfv, PFNGLGETVERTEXATTRIBFVPROC, GLuint index, GLenum pname, GLfloat *params) \
x(void, glGetVertexAttribiv, PFNGLGETVERTEXATTRIBIVPROC, GLuint index, GLenum pname, GLint *params) \
x(void, glGetVertexAttribPointerv, PFNGLGETVERTEXATTRIBPOINTERVPROC, GLuint index, GLenum pname, void **pointer) \
x(GLboolean, glIsProgram, PFNGLISPROGRAMPROC, GLuint program) \
x(GLboolean, glIsShader, PFNGLISSHADERPROC, GLuint shader) \
x(void, glLinkProgram, PFNGLLINKPROGRAMPROC, GLuint program) \
x(void, glShaderSource, PFNGLSHADERSOURCEPROC, GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) \
x(void, glUseProgram, PFNGLUSEPROGRAMPROC, GLuint program) \
x(void, glUniform1f, PFNGLUNIFORM1FPROC, GLint location, GLfloat v0) \
x(void, glUniform2f, PFNGLUNIFORM2FPROC, GLint location, GLfloat v0, GLfloat v1) \
x(void, glUniform3f, PFNGLUNIFORM3FPROC, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) \
x(void, glUniform4f, PFNGLUNIFORM4FPROC, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) \
x(void, glUniform1i, PFNGLUNIFORM1IPROC, GLint location, GLint v0) \
x(void, glUniform2i, PFNGLUNIFORM2IPROC, GLint location, GLint v0, GLint v1) \
x(void, glUniform3i, PFNGLUNIFORM3IPROC, GLint location, GLint v0, GLint v1, GLint v2) \
x(void, glUniform4i, PFNGLUNIFORM4IPROC, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) \
x(void, glUniform1fv, PFNGLUNIFORM1FVPROC, GLint location, GLsizei count, const GLfloat *value) \
x(void, glUniform2fv, PFNGLUNIFORM2FVPROC, GLint location, GLsizei count, const GLfloat *value) \
x(void, glUniform3fv, PFNGLUNIFORM3FVPROC, GLint location, GLsizei count, const GLfloat *value) \
x(void, glUniform4fv, PFNGLUNIFORM4FVPROC, GLint location, GLsizei count, const GLfloat *value) \
x(void, glUniform1iv, PFNGLUNIFORM1IVPROC, GLint location, GLsizei count, const GLint *value) \
x(void, glUniform2iv, PFNGLUNIFORM2IVPROC, GLint location, GLsizei count, const GLint *value) \
x(void, glUniform3iv, PFNGLUNIFORM3IVPROC, GLint location, GLsizei count, const GLint *value) \
x(void, glUniform4iv, PFNGLUNIFORM4IVPROC, GLint location, GLsizei count, const GLint *value) \
x(void, glUniformMatrix2fv, PFNGLUNIFORMMATRIX2FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix3fv, PFNGLUNIFORMMATRIX3FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix4fv, PFNGLUNIFORMMATRIX4FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glValidateProgram, PFNGLVALIDATEPROGRAMPROC, GLuint program) \
x(void, glVertexAttrib1d, PFNGLVERTEXATTRIB1DPROC, GLuint index, GLdouble x) \
x(void, glVertexAttrib1dv, PFNGLVERTEXATTRIB1DVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib1f, PFNGLVERTEXATTRIB1FPROC, GLuint index, GLfloat x) \
x(void, glVertexAttrib1fv, PFNGLVERTEXATTRIB1FVPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib1s, PFNGLVERTEXATTRIB1SPROC, GLuint index, GLshort x) \
x(void, glVertexAttrib1sv, PFNGLVERTEXATTRIB1SVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib2d, PFNGLVERTEXATTRIB2DPROC, GLuint index, GLdouble x, GLdouble y) \
x(void, glVertexAttrib2dv, PFNGLVERTEXATTRIB2DVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib2f, PFNGLVERTEXATTRIB2FPROC, GLuint index, GLfloat x, GLfloat y) \
x(void, glVertexAttrib2fv, PFNGLVERTEXATTRIB2FVPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib2s, PFNGLVERTEXATTRIB2SPROC, GLuint index, GLshort x, GLshort y) \
x(void, glVertexAttrib2sv, PFNGLVERTEXATTRIB2SVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib3d, PFNGLVERTEXATTRIB3DPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z) \
x(void, glVertexAttrib3dv, PFNGLVERTEXATTRIB3DVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib3f, PFNGLVERTEXATTRIB3FPROC, GLuint index, GLfloat x, GLfloat y, GLfloat z) \
x(void, glVertexAttrib3fv, PFNGLVERTEXATTRIB3FVPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib3s, PFNGLVERTEXATTRIB3SPROC, GLuint index, GLshort x, GLshort y, GLshort z) \
x(void, glVertexAttrib3sv, PFNGLVERTEXATTRIB3SVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib4Nbv, PFNGLVERTEXATTRIB4NBVPROC, GLuint index, const GLbyte *v) \
x(void, glVertexAttrib4Niv, PFNGLVERTEXATTRIB4NIVPROC, GLuint index, const GLint *v) \
x(void, glVertexAttrib4Nsv, PFNGLVERTEXATTRIB4NSVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib4Nub, PFNGLVERTEXATTRIB4NUBPROC, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) \
x(void, glVertexAttrib4Nubv, PFNGLVERTEXATTRIB4NUBVPROC, GLuint index, const GLubyte *v) \
x(void, glVertexAttrib4Nuiv, PFNGLVERTEXATTRIB4NUIVPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttrib4Nusv, PFNGLVERTEXATTRIB4NUSVPROC, GLuint index, const GLushort *v) \
x(void, glVertexAttrib4bv, PFNGLVERTEXATTRIB4BVPROC, GLuint index, const GLbyte *v) \
x(void, glVertexAttrib4d, PFNGLVERTEXATTRIB4DPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glVertexAttrib4dv, PFNGLVERTEXATTRIB4DVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib4f, PFNGLVERTEXATTRIB4FPROC, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glVertexAttrib4fv, PFNGLVERTEXATTRIB4FVPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib4iv, PFNGLVERTEXATTRIB4IVPROC, GLuint index, const GLint *v) \
x(void, glVertexAttrib4s, PFNGLVERTEXATTRIB4SPROC, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) \
x(void, glVertexAttrib4sv, PFNGLVERTEXATTRIB4SVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib4ubv, PFNGLVERTEXATTRIB4UBVPROC, GLuint index, const GLubyte *v) \
x(void, glVertexAttrib4uiv, PFNGLVERTEXATTRIB4UIVPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttrib4usv, PFNGLVERTEXATTRIB4USVPROC, GLuint index, const GLushort *v) \
x(void, glVertexAttribPointer, PFNGLVERTEXATTRIBPOINTERPROC, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) \
x(void, glUniformMatrix2x3fv, PFNGLUNIFORMMATRIX2X3FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix3x2fv, PFNGLUNIFORMMATRIX3X2FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix2x4fv, PFNGLUNIFORMMATRIX2X4FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix4x2fv, PFNGLUNIFORMMATRIX4X2FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix3x4fv, PFNGLUNIFORMMATRIX3X4FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix4x3fv, PFNGLUNIFORMMATRIX4X3FVPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glColorMaski, PFNGLCOLORMASKIPROC, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) \
x(void, glGetBooleani_v, PFNGLGETBOOLEANI_VPROC, GLenum target, GLuint index, GLboolean *data) \
x(void, glGetIntegeri_v, PFNGLGETINTEGERI_VPROC, GLenum target, GLuint index, GLint *data) \
x(void, glEnablei, PFNGLENABLEIPROC, GLenum target, GLuint index) \
x(void, glDisablei, PFNGLDISABLEIPROC, GLenum target, GLuint index) \
x(GLboolean, glIsEnabledi, PFNGLISENABLEDIPROC, GLenum target, GLuint index) \
x(void, glBeginTransformFeedback, PFNGLBEGINTRANSFORMFEEDBACKPROC, GLenum primitiveMode) \
x(void, glEndTransformFeedback, PFNGLENDTRANSFORMFEEDBACKPROC, void) \
x(void, glBindBufferRange, PFNGLBINDBUFFERRANGEPROC, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) \
x(void, glBindBufferBase, PFNGLBINDBUFFERBASEPROC, GLenum target, GLuint index, GLuint buffer) \
x(void, glTransformFeedbackVaryings, PFNGLTRANSFORMFEEDBACKVARYINGSPROC, GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) \
x(void, glGetTransformFeedbackVarying, PFNGLGETTRANSFORMFEEDBACKVARYINGPROC, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) \
x(void, glClampColor, PFNGLCLAMPCOLORPROC, GLenum target, GLenum clamp) \
x(void, glBeginConditionalRender, PFNGLBEGINCONDITIONALRENDERPROC, GLuint id, GLenum mode) \
x(void, glEndConditionalRender, PFNGLENDCONDITIONALRENDERPROC, void) \
x(void, glVertexAttribIPointer, PFNGLVERTEXATTRIBIPOINTERPROC, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glGetVertexAttribIiv, PFNGLGETVERTEXATTRIBIIVPROC, GLuint index, GLenum pname, GLint *params) \
x(void, glGetVertexAttribIuiv, PFNGLGETVERTEXATTRIBIUIVPROC, GLuint index, GLenum pname, GLuint *params) \
x(void, glVertexAttribI1i, PFNGLVERTEXATTRIBI1IPROC, GLuint index, GLint x) \
x(void, glVertexAttribI2i, PFNGLVERTEXATTRIBI2IPROC, GLuint index, GLint x, GLint y) \
x(void, glVertexAttribI3i, PFNGLVERTEXATTRIBI3IPROC, GLuint index, GLint x, GLint y, GLint z) \
x(void, glVertexAttribI4i, PFNGLVERTEXATTRIBI4IPROC, GLuint index, GLint x, GLint y, GLint z, GLint w) \
x(void, glVertexAttribI1ui, PFNGLVERTEXATTRIBI1UIPROC, GLuint index, GLuint x) \
x(void, glVertexAttribI2ui, PFNGLVERTEXATTRIBI2UIPROC, GLuint index, GLuint x, GLuint y) \
x(void, glVertexAttribI3ui, PFNGLVERTEXATTRIBI3UIPROC, GLuint index, GLuint x, GLuint y, GLuint z) \
x(void, glVertexAttribI4ui, PFNGLVERTEXATTRIBI4UIPROC, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) \
x(void, glVertexAttribI1iv, PFNGLVERTEXATTRIBI1IVPROC, GLuint index, const GLint *v) \
x(void, glVertexAttribI2iv, PFNGLVERTEXATTRIBI2IVPROC, GLuint index, const GLint *v) \
x(void, glVertexAttribI3iv, PFNGLVERTEXATTRIBI3IVPROC, GLuint index, const GLint *v) \
x(void, glVertexAttribI4iv, PFNGLVERTEXATTRIBI4IVPROC, GLuint index, const GLint *v) \
x(void, glVertexAttribI1uiv, PFNGLVERTEXATTRIBI1UIVPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttribI2uiv, PFNGLVERTEXATTRIBI2UIVPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttribI3uiv, PFNGLVERTEXATTRIBI3UIVPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttribI4uiv, PFNGLVERTEXATTRIBI4UIVPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttribI4bv, PFNGLVERTEXATTRIBI4BVPROC, GLuint index, const GLbyte *v) \
x(void, glVertexAttribI4sv, PFNGLVERTEXATTRIBI4SVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttribI4ubv, PFNGLVERTEXATTRIBI4UBVPROC, GLuint index, const GLubyte *v) \
x(void, glVertexAttribI4usv, PFNGLVERTEXATTRIBI4USVPROC, GLuint index, const GLushort *v) \
x(void, glGetUniformuiv, PFNGLGETUNIFORMUIVPROC, GLuint program, GLint location, GLuint *params) \
x(void, glBindFragDataLocation, PFNGLBINDFRAGDATALOCATIONPROC, GLuint program, GLuint color, const GLchar *name) \
x(GLint, glGetFragDataLocation, PFNGLGETFRAGDATALOCATIONPROC, GLuint program, const GLchar *name) \
x(void, glUniform1ui, PFNGLUNIFORM1UIPROC, GLint location, GLuint v0) \
x(void, glUniform2ui, PFNGLUNIFORM2UIPROC, GLint location, GLuint v0, GLuint v1) \
x(void, glUniform3ui, PFNGLUNIFORM3UIPROC, GLint location, GLuint v0, GLuint v1, GLuint v2) \
x(void, glUniform4ui, PFNGLUNIFORM4UIPROC, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) \
x(void, glUniform1uiv, PFNGLUNIFORM1UIVPROC, GLint location, GLsizei count, const GLuint *value) \
x(void, glUniform2uiv, PFNGLUNIFORM2UIVPROC, GLint location, GLsizei count, const GLuint *value) \
x(void, glUniform3uiv, PFNGLUNIFORM3UIVPROC, GLint location, GLsizei count, const GLuint *value) \
x(void, glUniform4uiv, PFNGLUNIFORM4UIVPROC, GLint location, GLsizei count, const GLuint *value) \
x(void, glTexParameterIiv, PFNGLTEXPARAMETERIIVPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glTexParameterIuiv, PFNGLTEXPARAMETERIUIVPROC, GLenum target, GLenum pname, const GLuint *params) \
x(void, glGetTexParameterIiv, PFNGLGETTEXPARAMETERIIVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetTexParameterIuiv, PFNGLGETTEXPARAMETERIUIVPROC, GLenum target, GLenum pname, GLuint *params) \
x(void, glClearBufferiv, PFNGLCLEARBUFFERIVPROC, GLenum buffer, GLint drawbuffer, const GLint *value) \
x(void, glClearBufferuiv, PFNGLCLEARBUFFERUIVPROC, GLenum buffer, GLint drawbuffer, const GLuint *value) \
x(void, glClearBufferfv, PFNGLCLEARBUFFERFVPROC, GLenum buffer, GLint drawbuffer, const GLfloat *value) \
x(void, glClearBufferfi, PFNGLCLEARBUFFERFIPROC, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) \
x(GLboolean, glIsRenderbuffer, PFNGLISRENDERBUFFERPROC, GLuint renderbuffer) \
x(void, glBindRenderbuffer, PFNGLBINDRENDERBUFFERPROC, GLenum target, GLuint renderbuffer) \
x(void, glDeleteRenderbuffers, PFNGLDELETERENDERBUFFERSPROC, GLsizei n, const GLuint *renderbuffers) \
x(void, glGenRenderbuffers, PFNGLGENRENDERBUFFERSPROC, GLsizei n, GLuint *renderbuffers) \
x(void, glRenderbufferStorage, PFNGLRENDERBUFFERSTORAGEPROC, GLenum target, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glGetRenderbufferParameteriv, PFNGLGETRENDERBUFFERPARAMETERIVPROC, GLenum target, GLenum pname, GLint *params) \
x(GLboolean, glIsFramebuffer, PFNGLISFRAMEBUFFERPROC, GLuint framebuffer) \
x(void, glBindFramebuffer, PFNGLBINDFRAMEBUFFERPROC, GLenum target, GLuint framebuffer) \
x(void, glDeleteFramebuffers, PFNGLDELETEFRAMEBUFFERSPROC, GLsizei n, const GLuint *framebuffers) \
x(void, glGenFramebuffers, PFNGLGENFRAMEBUFFERSPROC, GLsizei n, GLuint *framebuffers) \
x(GLenum, glCheckFramebufferStatus, PFNGLCHECKFRAMEBUFFERSTATUSPROC, GLenum target) \
x(void, glFramebufferTexture1D, PFNGLFRAMEBUFFERTEXTURE1DPROC, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) \
x(void, glFramebufferTexture2D, PFNGLFRAMEBUFFERTEXTURE2DPROC, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) \
x(void, glFramebufferTexture3D, PFNGLFRAMEBUFFERTEXTURE3DPROC, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) \
x(void, glFramebufferRenderbuffer, PFNGLFRAMEBUFFERRENDERBUFFERPROC, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) \
x(void, glGetFramebufferAttachmentParameteriv, PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, GLenum target, GLenum attachment, GLenum pname, GLint *params) \
x(void, glGenerateMipmap, PFNGLGENERATEMIPMAPPROC, GLenum target) \
x(void, glBlitFramebuffer, PFNGLBLITFRAMEBUFFERPROC, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) \
x(void, glRenderbufferStorageMultisample, PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glFramebufferTextureLayer, PFNGLFRAMEBUFFERTEXTURELAYERPROC, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) \
x(void, glFlushMappedBufferRange, PFNGLFLUSHMAPPEDBUFFERRANGEPROC, GLenum target, GLintptr offset, GLsizeiptr length) \
x(void, glBindVertexArray, PFNGLBINDVERTEXARRAYPROC, GLuint array) \
x(void, glDeleteVertexArrays, PFNGLDELETEVERTEXARRAYSPROC, GLsizei n, const GLuint *arrays) \
x(void, glGenVertexArrays, PFNGLGENVERTEXARRAYSPROC, GLsizei n, GLuint *arrays) \
x(GLboolean, glIsVertexArray, PFNGLISVERTEXARRAYPROC, GLuint array) \
x(void, glDrawArraysInstanced, PFNGLDRAWARRAYSINSTANCEDPROC, GLenum mode, GLint first, GLsizei count, GLsizei instancecount) \
x(void, glDrawElementsInstanced, PFNGLDRAWELEMENTSINSTANCEDPROC, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount) \
x(void, glTexBuffer, PFNGLTEXBUFFERPROC, GLenum target, GLenum internalformat, GLuint buffer) \
x(void, glPrimitiveRestartIndex, PFNGLPRIMITIVERESTARTINDEXPROC, GLuint index) \
x(void, glCopyBufferSubData, PFNGLCOPYBUFFERSUBDATAPROC, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) \
x(void, glGetUniformIndices, PFNGLGETUNIFORMINDICESPROC, GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices) \
x(void, glGetActiveUniformsiv, PFNGLGETACTIVEUNIFORMSIVPROC, GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params) \
x(void, glGetActiveUniformName, PFNGLGETACTIVEUNIFORMNAMEPROC, GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName) \
x(GLuint, glGetUniformBlockIndex, PFNGLGETUNIFORMBLOCKINDEXPROC, GLuint program, const GLchar *uniformBlockName) \
x(void, glGetActiveUniformBlockiv, PFNGLGETACTIVEUNIFORMBLOCKIVPROC, GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params) \
x(void, glGetActiveUniformBlockName, PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC, GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName) \
x(void, glUniformBlockBinding, PFNGLUNIFORMBLOCKBINDINGPROC, GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) \
x(void, glDrawElementsBaseVertex, PFNGLDRAWELEMENTSBASEVERTEXPROC, GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex) \
x(void, glDrawRangeElementsBaseVertex, PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex) \
x(void, glDrawElementsInstancedBaseVertex, PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex) \
x(void, glMultiDrawElementsBaseVertex, PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex) \
x(void, glProvokingVertex, PFNGLPROVOKINGVERTEXPROC, GLenum mode) \
x(GLsync, glFenceSync, PFNGLFENCESYNCPROC, GLenum condition, GLbitfield flags) \
x(GLboolean, glIsSync, PFNGLISSYNCPROC, GLsync sync) \
x(void, glDeleteSync, PFNGLDELETESYNCPROC, GLsync sync) \
x(GLenum, glClientWaitSync, PFNGLCLIENTWAITSYNCPROC, GLsync sync, GLbitfield flags, GLuint64 timeout) \
x(void, glWaitSync, PFNGLWAITSYNCPROC, GLsync sync, GLbitfield flags, GLuint64 timeout) \
x(void, glGetInteger64v, PFNGLGETINTEGER64VPROC, GLenum pname, GLint64 *data) \
x(void, glGetSynciv, PFNGLGETSYNCIVPROC, GLsync sync, GLenum pname, GLsizei count, GLsizei *length, GLint *values) \
x(void, glGetInteger64i_v, PFNGLGETINTEGER64I_VPROC, GLenum target, GLuint index, GLint64 *data) \
x(void, glGetBufferParameteri64v, PFNGLGETBUFFERPARAMETERI64VPROC, GLenum target, GLenum pname, GLint64 *params) \
x(void, glFramebufferTexture, PFNGLFRAMEBUFFERTEXTUREPROC, GLenum target, GLenum attachment, GLuint texture, GLint level) \
x(void, glTexImage2DMultisample, PFNGLTEXIMAGE2DMULTISAMPLEPROC, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) \
x(void, glTexImage3DMultisample, PFNGLTEXIMAGE3DMULTISAMPLEPROC, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) \
x(void, glGetMultisamplefv, PFNGLGETMULTISAMPLEFVPROC, GLenum pname, GLuint index, GLfloat *val) \
x(void, glSampleMaski, PFNGLSAMPLEMASKIPROC, GLuint maskNumber, GLbitfield mask) \
x(void, glBindFragDataLocationIndexed, PFNGLBINDFRAGDATALOCATIONINDEXEDPROC, GLuint program, GLuint colorNumber, GLuint index, const GLchar *name) \
x(GLint, glGetFragDataIndex, PFNGLGETFRAGDATAINDEXPROC, GLuint program, const GLchar *name) \
x(void, glGenSamplers, PFNGLGENSAMPLERSPROC, GLsizei count, GLuint *samplers) \
x(void, glDeleteSamplers, PFNGLDELETESAMPLERSPROC, GLsizei count, const GLuint *samplers) \
x(GLboolean, glIsSampler, PFNGLISSAMPLERPROC, GLuint sampler) \
x(void, glBindSampler, PFNGLBINDSAMPLERPROC, GLuint unit, GLuint sampler) \
x(void, glSamplerParameteri, PFNGLSAMPLERPARAMETERIPROC, GLuint sampler, GLenum pname, GLint param) \
x(void, glSamplerParameteriv, PFNGLSAMPLERPARAMETERIVPROC, GLuint sampler, GLenum pname, const GLint *param) \
x(void, glSamplerParameterf, PFNGLSAMPLERPARAMETERFPROC, GLuint sampler, GLenum pname, GLfloat param) \
x(void, glSamplerParameterfv, PFNGLSAMPLERPARAMETERFVPROC, GLuint sampler, GLenum pname, const GLfloat *param) \
x(void, glSamplerParameterIiv, PFNGLSAMPLERPARAMETERIIVPROC, GLuint sampler, GLenum pname, const GLint *param) \
x(void, glSamplerParameterIuiv, PFNGLSAMPLERPARAMETERIUIVPROC, GLuint sampler, GLenum pname, const GLuint *param) \
x(void, glGetSamplerParameteriv, PFNGLGETSAMPLERPARAMETERIVPROC, GLuint sampler, GLenum pname, GLint *params) \
x(void, glGetSamplerParameterIiv, PFNGLGETSAMPLERPARAMETERIIVPROC, GLuint sampler, GLenum pname, GLint *params) \
x(void, glGetSamplerParameterfv, PFNGLGETSAMPLERPARAMETERFVPROC, GLuint sampler, GLenum pname, GLfloat *params) \
x(void, glGetSamplerParameterIuiv, PFNGLGETSAMPLERPARAMETERIUIVPROC, GLuint sampler, GLenum pname, GLuint *params) \
x(void, glQueryCounter, PFNGLQUERYCOUNTERPROC, GLuint id, GLenum target) \
x(void, glGetQueryObjecti64v, PFNGLGETQUERYOBJECTI64VPROC, GLuint id, GLenum pname, GLint64 *params) \
x(void, glGetQueryObjectui64v, PFNGLGETQUERYOBJECTUI64VPROC, GLuint id, GLenum pname, GLuint64 *params) \
x(void, glVertexAttribDivisor, PFNGLVERTEXATTRIBDIVISORPROC, GLuint index, GLuint divisor) \
x(void, glVertexAttribP1ui, PFNGLVERTEXATTRIBP1UIPROC, GLuint index, GLenum type, GLboolean normalized, GLuint value) \
x(void, glVertexAttribP1uiv, PFNGLVERTEXATTRIBP1UIVPROC, GLuint index, GLenum type, GLboolean normalized, const GLuint *value) \
x(void, glVertexAttribP2ui, PFNGLVERTEXATTRIBP2UIPROC, GLuint index, GLenum type, GLboolean normalized, GLuint value) \
x(void, glVertexAttribP2uiv, PFNGLVERTEXATTRIBP2UIVPROC, GLuint index, GLenum type, GLboolean normalized, const GLuint *value) \
x(void, glVertexAttribP3ui, PFNGLVERTEXATTRIBP3UIPROC, GLuint index, GLenum type, GLboolean normalized, GLuint value) \
x(void, glVertexAttribP3uiv, PFNGLVERTEXATTRIBP3UIVPROC, GLuint index, GLenum type, GLboolean normalized, const GLuint *value) \
x(void, glVertexAttribP4ui, PFNGLVERTEXATTRIBP4UIPROC, GLuint index, GLenum type, GLboolean normalized, GLuint value) \
x(void, glVertexAttribP4uiv, PFNGLVERTEXATTRIBP4UIVPROC, GLuint index, GLenum type, GLboolean normalized, const GLuint *value) \
x(void, glVertexP2ui, PFNGLVERTEXP2UIPROC, GLenum type, GLuint value) \
x(void, glVertexP2uiv, PFNGLVERTEXP2UIVPROC, GLenum type, const GLuint *value) \
x(void, glVertexP3ui, PFNGLVERTEXP3UIPROC, GLenum type, GLuint value) \
x(void, glVertexP3uiv, PFNGLVERTEXP3UIVPROC, GLenum type, const GLuint *value) \
x(void, glVertexP4ui, PFNGLVERTEXP4UIPROC, GLenum type, GLuint value) \
x(void, glVertexP4uiv, PFNGLVERTEXP4UIVPROC, GLenum type, const GLuint *value) \
x(void, glTexCoordP1ui, PFNGLTEXCOORDP1UIPROC, GLenum type, GLuint coords) \
x(void, glTexCoordP1uiv, PFNGLTEXCOORDP1UIVPROC, GLenum type, const GLuint *coords) \
x(void, glTexCoordP2ui, PFNGLTEXCOORDP2UIPROC, GLenum type, GLuint coords) \
x(void, glTexCoordP2uiv, PFNGLTEXCOORDP2UIVPROC, GLenum type, const GLuint *coords) \
x(void, glTexCoordP3ui, PFNGLTEXCOORDP3UIPROC, GLenum type, GLuint coords) \
x(void, glTexCoordP3uiv, PFNGLTEXCOORDP3UIVPROC, GLenum type, const GLuint *coords) \
x(void, glTexCoordP4ui, PFNGLTEXCOORDP4UIPROC, GLenum type, GLuint coords) \
x(void, glTexCoordP4uiv, PFNGLTEXCOORDP4UIVPROC, GLenum type, const GLuint *coords) \
x(void, glMultiTexCoordP1ui, PFNGLMULTITEXCOORDP1UIPROC, GLenum texture, GLenum type, GLuint coords) \
x(void, glMultiTexCoordP1uiv, PFNGLMULTITEXCOORDP1UIVPROC, GLenum texture, GLenum type, const GLuint *coords) \
x(void, glMultiTexCoordP2ui, PFNGLMULTITEXCOORDP2UIPROC, GLenum texture, GLenum type, GLuint coords) \
x(void, glMultiTexCoordP2uiv, PFNGLMULTITEXCOORDP2UIVPROC, GLenum texture, GLenum type, const GLuint *coords) \
x(void, glMultiTexCoordP3ui, PFNGLMULTITEXCOORDP3UIPROC, GLenum texture, GLenum type, GLuint coords) \
x(void, glMultiTexCoordP3uiv, PFNGLMULTITEXCOORDP3UIVPROC, GLenum texture, GLenum type, const GLuint *coords) \
x(void, glMultiTexCoordP4ui, PFNGLMULTITEXCOORDP4UIPROC, GLenum texture, GLenum type, GLuint coords) \
x(void, glMultiTexCoordP4uiv, PFNGLMULTITEXCOORDP4UIVPROC, GLenum texture, GLenum type, const GLuint *coords) \
x(void, glNormalP3ui, PFNGLNORMALP3UIPROC, GLenum type, GLuint coords) \
x(void, glNormalP3uiv, PFNGLNORMALP3UIVPROC, GLenum type, const GLuint *coords) \
x(void, glColorP3ui, PFNGLCOLORP3UIPROC, GLenum type, GLuint color) \
x(void, glColorP3uiv, PFNGLCOLORP3UIVPROC, GLenum type, const GLuint *color) \
x(void, glColorP4ui, PFNGLCOLORP4UIPROC, GLenum type, GLuint color) \
x(void, glColorP4uiv, PFNGLCOLORP4UIVPROC, GLenum type, const GLuint *color) \
x(void, glSecondaryColorP3ui, PFNGLSECONDARYCOLORP3UIPROC, GLenum type, GLuint color) \
x(void, glSecondaryColorP3uiv, PFNGLSECONDARYCOLORP3UIVPROC, GLenum type, const GLuint *color) \
x(void, glMinSampleShading, PFNGLMINSAMPLESHADINGPROC, GLfloat value) \
x(void, glBlendEquationi, PFNGLBLENDEQUATIONIPROC, GLuint buf, GLenum mode) \
x(void, glBlendEquationSeparatei, PFNGLBLENDEQUATIONSEPARATEIPROC, GLuint buf, GLenum modeRGB, GLenum modeAlpha) \
x(void, glBlendFunci, PFNGLBLENDFUNCIPROC, GLuint buf, GLenum src, GLenum dst) \
x(void, glBlendFuncSeparatei, PFNGLBLENDFUNCSEPARATEIPROC, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) \
x(void, glDrawArraysIndirect, PFNGLDRAWARRAYSINDIRECTPROC, GLenum mode, const void *indirect) \
x(void, glDrawElementsIndirect, PFNGLDRAWELEMENTSINDIRECTPROC, GLenum mode, GLenum type, const void *indirect) \
x(void, glUniform1d, PFNGLUNIFORM1DPROC, GLint location, GLdouble x) \
x(void, glUniform2d, PFNGLUNIFORM2DPROC, GLint location, GLdouble x, GLdouble y) \
x(void, glUniform3d, PFNGLUNIFORM3DPROC, GLint location, GLdouble x, GLdouble y, GLdouble z) \
x(void, glUniform4d, PFNGLUNIFORM4DPROC, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glUniform1dv, PFNGLUNIFORM1DVPROC, GLint location, GLsizei count, const GLdouble *value) \
x(void, glUniform2dv, PFNGLUNIFORM2DVPROC, GLint location, GLsizei count, const GLdouble *value) \
x(void, glUniform3dv, PFNGLUNIFORM3DVPROC, GLint location, GLsizei count, const GLdouble *value) \
x(void, glUniform4dv, PFNGLUNIFORM4DVPROC, GLint location, GLsizei count, const GLdouble *value) \
x(void, glUniformMatrix2dv, PFNGLUNIFORMMATRIX2DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glUniformMatrix3dv, PFNGLUNIFORMMATRIX3DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glUniformMatrix4dv, PFNGLUNIFORMMATRIX4DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glUniformMatrix2x3dv, PFNGLUNIFORMMATRIX2X3DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glUniformMatrix2x4dv, PFNGLUNIFORMMATRIX2X4DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glUniformMatrix3x2dv, PFNGLUNIFORMMATRIX3X2DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glUniformMatrix3x4dv, PFNGLUNIFORMMATRIX3X4DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glUniformMatrix4x2dv, PFNGLUNIFORMMATRIX4X2DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glUniformMatrix4x3dv, PFNGLUNIFORMMATRIX4X3DVPROC, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glGetUniformdv, PFNGLGETUNIFORMDVPROC, GLuint program, GLint location, GLdouble *params) \
x(GLint, glGetSubroutineUniformLocation, PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC, GLuint program, GLenum shadertype, const GLchar *name) \
x(GLuint, glGetSubroutineIndex, PFNGLGETSUBROUTINEINDEXPROC, GLuint program, GLenum shadertype, const GLchar *name) \
x(void, glGetActiveSubroutineUniformiv, PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC, GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values) \
x(void, glGetActiveSubroutineUniformName, PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC, GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) \
x(void, glGetActiveSubroutineName, PFNGLGETACTIVESUBROUTINENAMEPROC, GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) \
x(void, glUniformSubroutinesuiv, PFNGLUNIFORMSUBROUTINESUIVPROC, GLenum shadertype, GLsizei count, const GLuint *indices) \
x(void, glGetUniformSubroutineuiv, PFNGLGETUNIFORMSUBROUTINEUIVPROC, GLenum shadertype, GLint location, GLuint *params) \
x(void, glGetProgramStageiv, PFNGLGETPROGRAMSTAGEIVPROC, GLuint program, GLenum shadertype, GLenum pname, GLint *values) \
x(void, glPatchParameteri, PFNGLPATCHPARAMETERIPROC, GLenum pname, GLint value) \
x(void, glPatchParameterfv, PFNGLPATCHPARAMETERFVPROC, GLenum pname, const GLfloat *values) \
x(void, glBindTransformFeedback, PFNGLBINDTRANSFORMFEEDBACKPROC, GLenum target, GLuint id) \
x(void, glDeleteTransformFeedbacks, PFNGLDELETETRANSFORMFEEDBACKSPROC, GLsizei n, const GLuint *ids) \
x(void, glGenTransformFeedbacks, PFNGLGENTRANSFORMFEEDBACKSPROC, GLsizei n, GLuint *ids) \
x(GLboolean, glIsTransformFeedback, PFNGLISTRANSFORMFEEDBACKPROC, GLuint id) \
x(void, glPauseTransformFeedback, PFNGLPAUSETRANSFORMFEEDBACKPROC, void) \
x(void, glResumeTransformFeedback, PFNGLRESUMETRANSFORMFEEDBACKPROC, void) \
x(void, glDrawTransformFeedback, PFNGLDRAWTRANSFORMFEEDBACKPROC, GLenum mode, GLuint id) \
x(void, glDrawTransformFeedbackStream, PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC, GLenum mode, GLuint id, GLuint stream) \
x(void, glBeginQueryIndexed, PFNGLBEGINQUERYINDEXEDPROC, GLenum target, GLuint index, GLuint id) \
x(void, glEndQueryIndexed, PFNGLENDQUERYINDEXEDPROC, GLenum target, GLuint index) \
x(void, glGetQueryIndexediv, PFNGLGETQUERYINDEXEDIVPROC, GLenum target, GLuint index, GLenum pname, GLint *params) \
x(void, glReleaseShaderCompiler, PFNGLRELEASESHADERCOMPILERPROC, void) \
x(void, glShaderBinary, PFNGLSHADERBINARYPROC, GLsizei count, const GLuint *shaders, GLenum binaryFormat, const void *binary, GLsizei length) \
x(void, glGetShaderPrecisionFormat, PFNGLGETSHADERPRECISIONFORMATPROC, GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision) \
x(void, glDepthRangef, PFNGLDEPTHRANGEFPROC, GLfloat n, GLfloat f) \
x(void, glClearDepthf, PFNGLCLEARDEPTHFPROC, GLfloat d) \
x(void, glGetProgramBinary, PFNGLGETPROGRAMBINARYPROC, GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary) \
x(void, glProgramBinary, PFNGLPROGRAMBINARYPROC, GLuint program, GLenum binaryFormat, const void *binary, GLsizei length) \
x(void, glProgramParameteri, PFNGLPROGRAMPARAMETERIPROC, GLuint program, GLenum pname, GLint value) \
x(void, glUseProgramStages, PFNGLUSEPROGRAMSTAGESPROC, GLuint pipeline, GLbitfield stages, GLuint program) \
x(void, glActiveShaderProgram, PFNGLACTIVESHADERPROGRAMPROC, GLuint pipeline, GLuint program) \
x(GLuint, glCreateShaderProgramv, PFNGLCREATESHADERPROGRAMVPROC, GLenum type, GLsizei count, const GLchar *const*strings) \
x(void, glBindProgramPipeline, PFNGLBINDPROGRAMPIPELINEPROC, GLuint pipeline) \
x(void, glDeleteProgramPipelines, PFNGLDELETEPROGRAMPIPELINESPROC, GLsizei n, const GLuint *pipelines) \
x(void, glGenProgramPipelines, PFNGLGENPROGRAMPIPELINESPROC, GLsizei n, GLuint *pipelines) \
x(GLboolean, glIsProgramPipeline, PFNGLISPROGRAMPIPELINEPROC, GLuint pipeline) \
x(void, glGetProgramPipelineiv, PFNGLGETPROGRAMPIPELINEIVPROC, GLuint pipeline, GLenum pname, GLint *params) \
x(void, glProgramUniform1i, PFNGLPROGRAMUNIFORM1IPROC, GLuint program, GLint location, GLint v0) \
x(void, glProgramUniform1iv, PFNGLPROGRAMUNIFORM1IVPROC, GLuint program, GLint location, GLsizei count, const GLint *value) \
x(void, glProgramUniform1f, PFNGLPROGRAMUNIFORM1FPROC, GLuint program, GLint location, GLfloat v0) \
x(void, glProgramUniform1fv, PFNGLPROGRAMUNIFORM1FVPROC, GLuint program, GLint location, GLsizei count, const GLfloat *value) \
x(void, glProgramUniform1d, PFNGLPROGRAMUNIFORM1DPROC, GLuint program, GLint location, GLdouble v0) \
x(void, glProgramUniform1dv, PFNGLPROGRAMUNIFORM1DVPROC, GLuint program, GLint location, GLsizei count, const GLdouble *value) \
x(void, glProgramUniform1ui, PFNGLPROGRAMUNIFORM1UIPROC, GLuint program, GLint location, GLuint v0) \
x(void, glProgramUniform1uiv, PFNGLPROGRAMUNIFORM1UIVPROC, GLuint program, GLint location, GLsizei count, const GLuint *value) \
x(void, glProgramUniform2i, PFNGLPROGRAMUNIFORM2IPROC, GLuint program, GLint location, GLint v0, GLint v1) \
x(void, glProgramUniform2iv, PFNGLPROGRAMUNIFORM2IVPROC, GLuint program, GLint location, GLsizei count, const GLint *value) \
x(void, glProgramUniform2f, PFNGLPROGRAMUNIFORM2FPROC, GLuint program, GLint location, GLfloat v0, GLfloat v1) \
x(void, glProgramUniform2fv, PFNGLPROGRAMUNIFORM2FVPROC, GLuint program, GLint location, GLsizei count, const GLfloat *value) \
x(void, glProgramUniform2d, PFNGLPROGRAMUNIFORM2DPROC, GLuint program, GLint location, GLdouble v0, GLdouble v1) \
x(void, glProgramUniform2dv, PFNGLPROGRAMUNIFORM2DVPROC, GLuint program, GLint location, GLsizei count, const GLdouble *value) \
x(void, glProgramUniform2ui, PFNGLPROGRAMUNIFORM2UIPROC, GLuint program, GLint location, GLuint v0, GLuint v1) \
x(void, glProgramUniform2uiv, PFNGLPROGRAMUNIFORM2UIVPROC, GLuint program, GLint location, GLsizei count, const GLuint *value) \
x(void, glProgramUniform3i, PFNGLPROGRAMUNIFORM3IPROC, GLuint program, GLint location, GLint v0, GLint v1, GLint v2) \
x(void, glProgramUniform3iv, PFNGLPROGRAMUNIFORM3IVPROC, GLuint program, GLint location, GLsizei count, const GLint *value) \
x(void, glProgramUniform3f, PFNGLPROGRAMUNIFORM3FPROC, GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) \
x(void, glProgramUniform3fv, PFNGLPROGRAMUNIFORM3FVPROC, GLuint program, GLint location, GLsizei count, const GLfloat *value) \
x(void, glProgramUniform3d, PFNGLPROGRAMUNIFORM3DPROC, GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) \
x(void, glProgramUniform3dv, PFNGLPROGRAMUNIFORM3DVPROC, GLuint program, GLint location, GLsizei count, const GLdouble *value) \
x(void, glProgramUniform3ui, PFNGLPROGRAMUNIFORM3UIPROC, GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) \
x(void, glProgramUniform3uiv, PFNGLPROGRAMUNIFORM3UIVPROC, GLuint program, GLint location, GLsizei count, const GLuint *value) \
x(void, glProgramUniform4i, PFNGLPROGRAMUNIFORM4IPROC, GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) \
x(void, glProgramUniform4iv, PFNGLPROGRAMUNIFORM4IVPROC, GLuint program, GLint location, GLsizei count, const GLint *value) \
x(void, glProgramUniform4f, PFNGLPROGRAMUNIFORM4FPROC, GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) \
x(void, glProgramUniform4fv, PFNGLPROGRAMUNIFORM4FVPROC, GLuint program, GLint location, GLsizei count, const GLfloat *value) \
x(void, glProgramUniform4d, PFNGLPROGRAMUNIFORM4DPROC, GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) \
x(void, glProgramUniform4dv, PFNGLPROGRAMUNIFORM4DVPROC, GLuint program, GLint location, GLsizei count, const GLdouble *value) \
x(void, glProgramUniform4ui, PFNGLPROGRAMUNIFORM4UIPROC, GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) \
x(void, glProgramUniform4uiv, PFNGLPROGRAMUNIFORM4UIVPROC, GLuint program, GLint location, GLsizei count, const GLuint *value) \
x(void, glProgramUniformMatrix2fv, PFNGLPROGRAMUNIFORMMATRIX2FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix3fv, PFNGLPROGRAMUNIFORMMATRIX3FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix4fv, PFNGLPROGRAMUNIFORMMATRIX4FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix2dv, PFNGLPROGRAMUNIFORMMATRIX2DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix3dv, PFNGLPROGRAMUNIFORMMATRIX3DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix4dv, PFNGLPROGRAMUNIFORMMATRIX4DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix2x3fv, PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix3x2fv, PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix2x4fv, PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix4x2fv, PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix3x4fv, PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix4x3fv, PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix2x3dv, PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix3x2dv, PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix2x4dv, PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix4x2dv, PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix3x4dv, PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix4x3dv, PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glValidateProgramPipeline, PFNGLVALIDATEPROGRAMPIPELINEPROC, GLuint pipeline) \
x(void, glGetProgramPipelineInfoLog, PFNGLGETPROGRAMPIPELINEINFOLOGPROC, GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog) \
x(void, glVertexAttribL1d, PFNGLVERTEXATTRIBL1DPROC, GLuint index, GLdouble x) \
x(void, glVertexAttribL2d, PFNGLVERTEXATTRIBL2DPROC, GLuint index, GLdouble x, GLdouble y) \
x(void, glVertexAttribL3d, PFNGLVERTEXATTRIBL3DPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z) \
x(void, glVertexAttribL4d, PFNGLVERTEXATTRIBL4DPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glVertexAttribL1dv, PFNGLVERTEXATTRIBL1DVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttribL2dv, PFNGLVERTEXATTRIBL2DVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttribL3dv, PFNGLVERTEXATTRIBL3DVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttribL4dv, PFNGLVERTEXATTRIBL4DVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttribLPointer, PFNGLVERTEXATTRIBLPOINTERPROC, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glGetVertexAttribLdv, PFNGLGETVERTEXATTRIBLDVPROC, GLuint index, GLenum pname, GLdouble *params) \
x(void, glViewportArrayv, PFNGLVIEWPORTARRAYVPROC, GLuint first, GLsizei count, const GLfloat *v) \
x(void, glViewportIndexedf, PFNGLVIEWPORTINDEXEDFPROC, GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) \
x(void, glViewportIndexedfv, PFNGLVIEWPORTINDEXEDFVPROC, GLuint index, const GLfloat *v) \
x(void, glScissorArrayv, PFNGLSCISSORARRAYVPROC, GLuint first, GLsizei count, const GLint *v) \
x(void, glScissorIndexed, PFNGLSCISSORINDEXEDPROC, GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) \
x(void, glScissorIndexedv, PFNGLSCISSORINDEXEDVPROC, GLuint index, const GLint *v) \
x(void, glDepthRangeArrayv, PFNGLDEPTHRANGEARRAYVPROC, GLuint first, GLsizei count, const GLdouble *v) \
x(void, glDepthRangeIndexed, PFNGLDEPTHRANGEINDEXEDPROC, GLuint index, GLdouble n, GLdouble f) \
x(void, glGetFloati_v, PFNGLGETFLOATI_VPROC, GLenum target, GLuint index, GLfloat *data) \
x(void, glGetDoublei_v, PFNGLGETDOUBLEI_VPROC, GLenum target, GLuint index, GLdouble *data) \
x(void, glDrawArraysInstancedBaseInstance, PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC, GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) \
x(void, glDrawElementsInstancedBaseInstance, PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance) \
x(void, glDrawElementsInstancedBaseVertexBaseInstance, PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) \
x(void, glGetInternalformativ, PFNGLGETINTERNALFORMATIVPROC, GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint *params) \
x(void, glGetActiveAtomicCounterBufferiv, PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC, GLuint program, GLuint bufferIndex, GLenum pname, GLint *params) \
x(void, glBindImageTexture, PFNGLBINDIMAGETEXTUREPROC, GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) \
x(void, glMemoryBarrier, PFNGLMEMORYBARRIERPROC, GLbitfield barriers) \
x(void, glTexStorage1D, PFNGLTEXSTORAGE1DPROC, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) \
x(void, glTexStorage2D, PFNGLTEXSTORAGE2DPROC, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glTexStorage3D, PFNGLTEXSTORAGE3DPROC, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) \
x(void, glDrawTransformFeedbackInstanced, PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC, GLenum mode, GLuint id, GLsizei instancecount) \
x(void, glDrawTransformFeedbackStreamInstanced, PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC, GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) \
x(void, glClearBufferData, PFNGLCLEARBUFFERDATAPROC, GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data) \
x(void, glClearBufferSubData, PFNGLCLEARBUFFERSUBDATAPROC, GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) \
x(void, glDispatchCompute, PFNGLDISPATCHCOMPUTEPROC, GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) \
x(void, glDispatchComputeIndirect, PFNGLDISPATCHCOMPUTEINDIRECTPROC, GLintptr indirect) \
x(void, glCopyImageSubData, PFNGLCOPYIMAGESUBDATAPROC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) \
x(void, glFramebufferParameteri, PFNGLFRAMEBUFFERPARAMETERIPROC, GLenum target, GLenum pname, GLint param) \
x(void, glGetFramebufferParameteriv, PFNGLGETFRAMEBUFFERPARAMETERIVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetInternalformati64v, PFNGLGETINTERNALFORMATI64VPROC, GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64 *params) \
x(void, glInvalidateTexSubImage, PFNGLINVALIDATETEXSUBIMAGEPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) \
x(void, glInvalidateTexImage, PFNGLINVALIDATETEXIMAGEPROC, GLuint texture, GLint level) \
x(void, glInvalidateBufferSubData, PFNGLINVALIDATEBUFFERSUBDATAPROC, GLuint buffer, GLintptr offset, GLsizeiptr length) \
x(void, glInvalidateBufferData, PFNGLINVALIDATEBUFFERDATAPROC, GLuint buffer) \
x(void, glInvalidateFramebuffer, PFNGLINVALIDATEFRAMEBUFFERPROC, GLenum target, GLsizei numAttachments, const GLenum *attachments) \
x(void, glInvalidateSubFramebuffer, PFNGLINVALIDATESUBFRAMEBUFFERPROC, GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glMultiDrawArraysIndirect, PFNGLMULTIDRAWARRAYSINDIRECTPROC, GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride) \
x(void, glMultiDrawElementsIndirect, PFNGLMULTIDRAWELEMENTSINDIRECTPROC, GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride) \
x(void, glGetProgramInterfaceiv, PFNGLGETPROGRAMINTERFACEIVPROC, GLuint program, GLenum programInterface, GLenum pname, GLint *params) \
x(GLuint, glGetProgramResourceIndex, PFNGLGETPROGRAMRESOURCEINDEXPROC, GLuint program, GLenum programInterface, const GLchar *name) \
x(void, glGetProgramResourceName, PFNGLGETPROGRAMRESOURCENAMEPROC, GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name) \
x(void, glGetProgramResourceiv, PFNGLGETPROGRAMRESOURCEIVPROC, GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLint *params) \
x(GLint, glGetProgramResourceLocation, PFNGLGETPROGRAMRESOURCELOCATIONPROC, GLuint program, GLenum programInterface, const GLchar *name) \
x(GLint, glGetProgramResourceLocationIndex, PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC, GLuint program, GLenum programInterface, const GLchar *name) \
x(void, glShaderStorageBlockBinding, PFNGLSHADERSTORAGEBLOCKBINDINGPROC, GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) \
x(void, glTexBufferRange, PFNGLTEXBUFFERRANGEPROC, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) \
x(void, glTexStorage2DMultisample, PFNGLTEXSTORAGE2DMULTISAMPLEPROC, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) \
x(void, glTexStorage3DMultisample, PFNGLTEXSTORAGE3DMULTISAMPLEPROC, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) \
x(void, glTextureView, PFNGLTEXTUREVIEWPROC, GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) \
x(void, glBindVertexBuffer, PFNGLBINDVERTEXBUFFERPROC, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) \
x(void, glVertexAttribFormat, PFNGLVERTEXATTRIBFORMATPROC, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) \
x(void, glVertexAttribIFormat, PFNGLVERTEXATTRIBIFORMATPROC, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) \
x(void, glVertexAttribLFormat, PFNGLVERTEXATTRIBLFORMATPROC, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) \
x(void, glVertexAttribBinding, PFNGLVERTEXATTRIBBINDINGPROC, GLuint attribindex, GLuint bindingindex) \
x(void, glVertexBindingDivisor, PFNGLVERTEXBINDINGDIVISORPROC, GLuint bindingindex, GLuint divisor) \
x(void, glDebugMessageControl, PFNGLDEBUGMESSAGECONTROLPROC, GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) \
x(void, glDebugMessageInsert, PFNGLDEBUGMESSAGEINSERTPROC, GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) \
x(void, glDebugMessageCallback, PFNGLDEBUGMESSAGECALLBACKPROC, GLDEBUGPROC callback, const void *userParam) \
x(GLuint, glGetDebugMessageLog, PFNGLGETDEBUGMESSAGELOGPROC, GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) \
x(void, glPushDebugGroup, PFNGLPUSHDEBUGGROUPPROC, GLenum source, GLuint id, GLsizei length, const GLchar *message) \
x(void, glPopDebugGroup, PFNGLPOPDEBUGGROUPPROC, void) \
x(void, glObjectLabel, PFNGLOBJECTLABELPROC, GLenum identifier, GLuint name, GLsizei length, const GLchar *label) \
x(void, glGetObjectLabel, PFNGLGETOBJECTLABELPROC, GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label) \
x(void, glObjectPtrLabel, PFNGLOBJECTPTRLABELPROC, const void *ptr, GLsizei length, const GLchar *label) \
x(void, glGetObjectPtrLabel, PFNGLGETOBJECTPTRLABELPROC, const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label) \
x(void, glBufferStorage, PFNGLBUFFERSTORAGEPROC, GLenum target, GLsizeiptr size, const void *data, GLbitfield flags) \
x(void, glClearTexImage, PFNGLCLEARTEXIMAGEPROC, GLuint texture, GLint level, GLenum format, GLenum type, const void *data) \
x(void, glClearTexSubImage, PFNGLCLEARTEXSUBIMAGEPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data) \
x(void, glBindBuffersBase, PFNGLBINDBUFFERSBASEPROC, GLenum target, GLuint first, GLsizei count, const GLuint *buffers) \
x(void, glBindBuffersRange, PFNGLBINDBUFFERSRANGEPROC, GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes) \
x(void, glBindTextures, PFNGLBINDTEXTURESPROC, GLuint first, GLsizei count, const GLuint *textures) \
x(void, glBindSamplers, PFNGLBINDSAMPLERSPROC, GLuint first, GLsizei count, const GLuint *samplers) \
x(void, glBindImageTextures, PFNGLBINDIMAGETEXTURESPROC, GLuint first, GLsizei count, const GLuint *textures) \
x(void, glBindVertexBuffers, PFNGLBINDVERTEXBUFFERSPROC, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) \
x(void, glClipControl, PFNGLCLIPCONTROLPROC, GLenum origin, GLenum depth) \
x(void, glCreateTransformFeedbacks, PFNGLCREATETRANSFORMFEEDBACKSPROC, GLsizei n, GLuint *ids) \
x(void, glTransformFeedbackBufferBase, PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC, GLuint xfb, GLuint index, GLuint buffer) \
x(void, glTransformFeedbackBufferRange, PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC, GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) \
x(void, glGetTransformFeedbackiv, PFNGLGETTRANSFORMFEEDBACKIVPROC, GLuint xfb, GLenum pname, GLint *param) \
x(void, glGetTransformFeedbacki_v, PFNGLGETTRANSFORMFEEDBACKI_VPROC, GLuint xfb, GLenum pname, GLuint index, GLint *param) \
x(void, glGetTransformFeedbacki64_v, PFNGLGETTRANSFORMFEEDBACKI64_VPROC, GLuint xfb, GLenum pname, GLuint index, GLint64 *param) \
x(void, glCreateBuffers, PFNGLCREATEBUFFERSPROC, GLsizei n, GLuint *buffers) \
x(void, glNamedBufferStorage, PFNGLNAMEDBUFFERSTORAGEPROC, GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) \
x(void, glNamedBufferData, PFNGLNAMEDBUFFERDATAPROC, GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) \
x(void, glNamedBufferSubData, PFNGLNAMEDBUFFERSUBDATAPROC, GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) \
x(void, glCopyNamedBufferSubData, PFNGLCOPYNAMEDBUFFERSUBDATAPROC, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) \
x(void, glClearNamedBufferData, PFNGLCLEARNAMEDBUFFERDATAPROC, GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) \
x(void, glClearNamedBufferSubData, PFNGLCLEARNAMEDBUFFERSUBDATAPROC, GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) \
x(GLboolean, glUnmapNamedBuffer, PFNGLUNMAPNAMEDBUFFERPROC, GLuint buffer) \
x(void, glFlushMappedNamedBufferRange, PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC, GLuint buffer, GLintptr offset, GLsizeiptr length) \
x(void, glGetNamedBufferParameteriv, PFNGLGETNAMEDBUFFERPARAMETERIVPROC, GLuint buffer, GLenum pname, GLint *params) \
x(void, glGetNamedBufferParameteri64v, PFNGLGETNAMEDBUFFERPARAMETERI64VPROC, GLuint buffer, GLenum pname, GLint64 *params) \
x(void, glGetNamedBufferPointerv, PFNGLGETNAMEDBUFFERPOINTERVPROC, GLuint buffer, GLenum pname, void **params) \
x(void, glGetNamedBufferSubData, PFNGLGETNAMEDBUFFERSUBDATAPROC, GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) \
x(void, glCreateFramebuffers, PFNGLCREATEFRAMEBUFFERSPROC, GLsizei n, GLuint *framebuffers) \
x(void, glNamedFramebufferRenderbuffer, PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC, GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) \
x(void, glNamedFramebufferParameteri, PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC, GLuint framebuffer, GLenum pname, GLint param) \
x(void, glNamedFramebufferTexture, PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) \
x(void, glNamedFramebufferTextureLayer, PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) \
x(void, glNamedFramebufferDrawBuffer, PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC, GLuint framebuffer, GLenum buf) \
x(void, glNamedFramebufferDrawBuffers, PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC, GLuint framebuffer, GLsizei n, const GLenum *bufs) \
x(void, glNamedFramebufferReadBuffer, PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC, GLuint framebuffer, GLenum src) \
x(void, glInvalidateNamedFramebufferData, PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC, GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments) \
x(void, glInvalidateNamedFramebufferSubData, PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC, GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glClearNamedFramebufferiv, PFNGLCLEARNAMEDFRAMEBUFFERIVPROC, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value) \
x(void, glClearNamedFramebufferuiv, PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value) \
x(void, glClearNamedFramebufferfv, PFNGLCLEARNAMEDFRAMEBUFFERFVPROC, GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value) \
x(void, glClearNamedFramebufferfi, PFNGLCLEARNAMEDFRAMEBUFFERFIPROC, GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) \
x(void, glBlitNamedFramebuffer, PFNGLBLITNAMEDFRAMEBUFFERPROC, GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) \
x(GLenum, glCheckNamedFramebufferStatus, PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC, GLuint framebuffer, GLenum target) \
x(void, glGetNamedFramebufferParameteriv, PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC, GLuint framebuffer, GLenum pname, GLint *param) \
x(void, glGetNamedFramebufferAttachmentParameteriv, PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC, GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) \
x(void, glCreateRenderbuffers, PFNGLCREATERENDERBUFFERSPROC, GLsizei n, GLuint *renderbuffers) \
x(void, glNamedRenderbufferStorage, PFNGLNAMEDRENDERBUFFERSTORAGEPROC, GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glNamedRenderbufferStorageMultisample, PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC, GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glGetNamedRenderbufferParameteriv, PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC, GLuint renderbuffer, GLenum pname, GLint *params) \
x(void, glCreateTextures, PFNGLCREATETEXTURESPROC, GLenum target, GLsizei n, GLuint *textures) \
x(void, glTextureBuffer, PFNGLTEXTUREBUFFERPROC, GLuint texture, GLenum internalformat, GLuint buffer) \
x(void, glTextureBufferRange, PFNGLTEXTUREBUFFERRANGEPROC, GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) \
x(void, glTextureStorage1D, PFNGLTEXTURESTORAGE1DPROC, GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width) \
x(void, glTextureStorage2D, PFNGLTEXTURESTORAGE2DPROC, GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glTextureStorage3D, PFNGLTEXTURESTORAGE3DPROC, GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) \
x(void, glTextureStorage2DMultisample, PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC, GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) \
x(void, glTextureStorage3DMultisample, PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC, GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) \
x(void, glTextureSubImage1D, PFNGLTEXTURESUBIMAGE1DPROC, GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) \
x(void, glTextureSubImage2D, PFNGLTEXTURESUBIMAGE2DPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) \
x(void, glTextureSubImage3D, PFNGLTEXTURESUBIMAGE3DPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) \
x(void, glCompressedTextureSubImage1D, PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC, GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) \
x(void, glCompressedTextureSubImage2D, PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) \
x(void, glCompressedTextureSubImage3D, PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) \
x(void, glCopyTextureSubImage1D, PFNGLCOPYTEXTURESUBIMAGE1DPROC, GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) \
x(void, glCopyTextureSubImage2D, PFNGLCOPYTEXTURESUBIMAGE2DPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glCopyTextureSubImage3D, PFNGLCOPYTEXTURESUBIMAGE3DPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glTextureParameterf, PFNGLTEXTUREPARAMETERFPROC, GLuint texture, GLenum pname, GLfloat param) \
x(void, glTextureParameterfv, PFNGLTEXTUREPARAMETERFVPROC, GLuint texture, GLenum pname, const GLfloat *param) \
x(void, glTextureParameteri, PFNGLTEXTUREPARAMETERIPROC, GLuint texture, GLenum pname, GLint param) \
x(void, glTextureParameterIiv, PFNGLTEXTUREPARAMETERIIVPROC, GLuint texture, GLenum pname, const GLint *params) \
x(void, glTextureParameterIuiv, PFNGLTEXTUREPARAMETERIUIVPROC, GLuint texture, GLenum pname, const GLuint *params) \
x(void, glTextureParameteriv, PFNGLTEXTUREPARAMETERIVPROC, GLuint texture, GLenum pname, const GLint *param) \
x(void, glGenerateTextureMipmap, PFNGLGENERATETEXTUREMIPMAPPROC, GLuint texture) \
x(void, glBindTextureUnit, PFNGLBINDTEXTUREUNITPROC, GLuint unit, GLuint texture) \
x(void, glGetTextureImage, PFNGLGETTEXTUREIMAGEPROC, GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) \
x(void, glGetCompressedTextureImage, PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC, GLuint texture, GLint level, GLsizei bufSize, void *pixels) \
x(void, glGetTextureLevelParameterfv, PFNGLGETTEXTURELEVELPARAMETERFVPROC, GLuint texture, GLint level, GLenum pname, GLfloat *params) \
x(void, glGetTextureLevelParameteriv, PFNGLGETTEXTURELEVELPARAMETERIVPROC, GLuint texture, GLint level, GLenum pname, GLint *params) \
x(void, glGetTextureParameterfv, PFNGLGETTEXTUREPARAMETERFVPROC, GLuint texture, GLenum pname, GLfloat *params) \
x(void, glGetTextureParameterIiv, PFNGLGETTEXTUREPARAMETERIIVPROC, GLuint texture, GLenum pname, GLint *params) \
x(void, glGetTextureParameterIuiv, PFNGLGETTEXTUREPARAMETERIUIVPROC, GLuint texture, GLenum pname, GLuint *params) \
x(void, glGetTextureParameteriv, PFNGLGETTEXTUREPARAMETERIVPROC, GLuint texture, GLenum pname, GLint *params) \
x(void, glCreateVertexArrays, PFNGLCREATEVERTEXARRAYSPROC, GLsizei n, GLuint *arrays) \
x(void, glDisableVertexArrayAttrib, PFNGLDISABLEVERTEXARRAYATTRIBPROC, GLuint vaobj, GLuint index) \
x(void, glEnableVertexArrayAttrib, PFNGLENABLEVERTEXARRAYATTRIBPROC, GLuint vaobj, GLuint index) \
x(void, glVertexArrayElementBuffer, PFNGLVERTEXARRAYELEMENTBUFFERPROC, GLuint vaobj, GLuint buffer) \
x(void, glVertexArrayVertexBuffer, PFNGLVERTEXARRAYVERTEXBUFFERPROC, GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) \
x(void, glVertexArrayVertexBuffers, PFNGLVERTEXARRAYVERTEXBUFFERSPROC, GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides) \
x(void, glVertexArrayAttribBinding, PFNGLVERTEXARRAYATTRIBBINDINGPROC, GLuint vaobj, GLuint attribindex, GLuint bindingindex) \
x(void, glVertexArrayAttribFormat, PFNGLVERTEXARRAYATTRIBFORMATPROC, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) \
x(void, glVertexArrayAttribIFormat, PFNGLVERTEXARRAYATTRIBIFORMATPROC, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) \
x(void, glVertexArrayAttribLFormat, PFNGLVERTEXARRAYATTRIBLFORMATPROC, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) \
x(void, glVertexArrayBindingDivisor, PFNGLVERTEXARRAYBINDINGDIVISORPROC, GLuint vaobj, GLuint bindingindex, GLuint divisor) \
x(void, glGetVertexArrayiv, PFNGLGETVERTEXARRAYIVPROC, GLuint vaobj, GLenum pname, GLint *param) \
x(void, glGetVertexArrayIndexediv, PFNGLGETVERTEXARRAYINDEXEDIVPROC, GLuint vaobj, GLuint index, GLenum pname, GLint *param) \
x(void, glGetVertexArrayIndexed64iv, PFNGLGETVERTEXARRAYINDEXED64IVPROC, GLuint vaobj, GLuint index, GLenum pname, GLint64 *param) \
x(void, glCreateSamplers, PFNGLCREATESAMPLERSPROC, GLsizei n, GLuint *samplers) \
x(void, glCreateProgramPipelines, PFNGLCREATEPROGRAMPIPELINESPROC, GLsizei n, GLuint *pipelines) \
x(void, glCreateQueries, PFNGLCREATEQUERIESPROC, GLenum target, GLsizei n, GLuint *ids) \
x(void, glGetQueryBufferObjecti64v, PFNGLGETQUERYBUFFEROBJECTI64VPROC, GLuint id, GLuint buffer, GLenum pname, GLintptr offset) \
x(void, glGetQueryBufferObjectiv, PFNGLGETQUERYBUFFEROBJECTIVPROC, GLuint id, GLuint buffer, GLenum pname, GLintptr offset) \
x(void, glGetQueryBufferObjectui64v, PFNGLGETQUERYBUFFEROBJECTUI64VPROC, GLuint id, GLuint buffer, GLenum pname, GLintptr offset) \
x(void, glGetQueryBufferObjectuiv, PFNGLGETQUERYBUFFEROBJECTUIVPROC, GLuint id, GLuint buffer, GLenum pname, GLintptr offset) \
x(void, glMemoryBarrierByRegion, PFNGLMEMORYBARRIERBYREGIONPROC, GLbitfield barriers) \
x(void, glGetTextureSubImage, PFNGLGETTEXTURESUBIMAGEPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels) \
x(void, glGetCompressedTextureSubImage, PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels) \
x(GLenum, glGetGraphicsResetStatus, PFNGLGETGRAPHICSRESETSTATUSPROC, void) \
x(void, glGetnCompressedTexImage, PFNGLGETNCOMPRESSEDTEXIMAGEPROC, GLenum target, GLint lod, GLsizei bufSize, void *pixels) \
x(void, glGetnTexImage, PFNGLGETNTEXIMAGEPROC, GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels) \
x(void, glGetnUniformdv, PFNGLGETNUNIFORMDVPROC, GLuint program, GLint location, GLsizei bufSize, GLdouble *params) \
x(void, glGetnUniformfv, PFNGLGETNUNIFORMFVPROC, GLuint program, GLint location, GLsizei bufSize, GLfloat *params) \
x(void, glGetnUniformiv, PFNGLGETNUNIFORMIVPROC, GLuint program, GLint location, GLsizei bufSize, GLint *params) \
x(void, glGetnUniformuiv, PFNGLGETNUNIFORMUIVPROC, GLuint program, GLint location, GLsizei bufSize, GLuint *params) \
x(void, glReadnPixels, PFNGLREADNPIXELSPROC, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) \
x(void, glGetnMapdv, PFNGLGETNMAPDVPROC, GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) \
x(void, glGetnMapfv, PFNGLGETNMAPFVPROC, GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) \
x(void, glGetnMapiv, PFNGLGETNMAPIVPROC, GLenum target, GLenum query, GLsizei bufSize, GLint *v) \
x(void, glGetnPixelMapfv, PFNGLGETNPIXELMAPFVPROC, GLenum map, GLsizei bufSize, GLfloat *values) \
x(void, glGetnPixelMapuiv, PFNGLGETNPIXELMAPUIVPROC, GLenum map, GLsizei bufSize, GLuint *values) \
x(void, glGetnPixelMapusv, PFNGLGETNPIXELMAPUSVPROC, GLenum map, GLsizei bufSize, GLushort *values) \
x(void, glGetnPolygonStipple, PFNGLGETNPOLYGONSTIPPLEPROC, GLsizei bufSize, GLubyte *pattern) \
x(void, glGetnColorTable, PFNGLGETNCOLORTABLEPROC, GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) \
x(void, glGetnConvolutionFilter, PFNGLGETNCONVOLUTIONFILTERPROC, GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) \
x(void, glGetnSeparableFilter, PFNGLGETNSEPARABLEFILTERPROC, GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) \
x(void, glGetnHistogram, PFNGLGETNHISTOGRAMPROC, GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) \
x(void, glGetnMinmax, PFNGLGETNMINMAXPROC, GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) \
x(void, glTextureBarrier, PFNGLTEXTUREBARRIERPROC, void) \
x(void, glSpecializeShader, PFNGLSPECIALIZESHADERPROC, GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue) \
x(void, glMultiDrawArraysIndirectCount, PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC, GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) \
x(void, glMultiDrawElementsIndirectCount, PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC, GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) \
x(void, glPolygonOffsetClamp, PFNGLPOLYGONOFFSETCLAMPPROC, GLfloat factor, GLfloat units, GLfloat clamp) \
/*x(void, glPrimitiveBoundingBoxARB, PFNGLPRIMITIVEBOUNDINGBOXARBPROC, GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW) \
x(GLuint64, glGetTextureHandleARB, PFNGLGETTEXTUREHANDLEARBPROC, GLuint texture) \
x(GLuint64, glGetTextureSamplerHandleARB, PFNGLGETTEXTURESAMPLERHANDLEARBPROC, GLuint texture, GLuint sampler) \
x(void, glMakeTextureHandleResidentARB, PFNGLMAKETEXTUREHANDLERESIDENTARBPROC, GLuint64 handle) \
x(void, glMakeTextureHandleNonResidentARB, PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC, GLuint64 handle) \
x(GLuint64, glGetImageHandleARB, PFNGLGETIMAGEHANDLEARBPROC, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) \
x(void, glMakeImageHandleResidentARB, PFNGLMAKEIMAGEHANDLERESIDENTARBPROC, GLuint64 handle, GLenum access) \
x(void, glMakeImageHandleNonResidentARB, PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC, GLuint64 handle) \
x(void, glUniformHandleui64ARB, PFNGLUNIFORMHANDLEUI64ARBPROC, GLint location, GLuint64 value) \
x(void, glUniformHandleui64vARB, PFNGLUNIFORMHANDLEUI64VARBPROC, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glProgramUniformHandleui64ARB, PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC, GLuint program, GLint location, GLuint64 value) \
x(void, glProgramUniformHandleui64vARB, PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC, GLuint program, GLint location, GLsizei count, const GLuint64 *values) \
x(GLboolean, glIsTextureHandleResidentARB, PFNGLISTEXTUREHANDLERESIDENTARBPROC, GLuint64 handle) \
x(GLboolean, glIsImageHandleResidentARB, PFNGLISIMAGEHANDLERESIDENTARBPROC, GLuint64 handle) \
x(void, glVertexAttribL1ui64ARB, PFNGLVERTEXATTRIBL1UI64ARBPROC, GLuint index, GLuint64EXT x) \
x(void, glVertexAttribL1ui64vARB, PFNGLVERTEXATTRIBL1UI64VARBPROC, GLuint index, const GLuint64EXT *v) \
x(void, glGetVertexAttribLui64vARB, PFNGLGETVERTEXATTRIBLUI64VARBPROC, GLuint index, GLenum pname, GLuint64EXT *params) \
x(GLsync, glCreateSyncFromCLeventARB, PFNGLCREATESYNCFROMCLEVENTARBPROC, struct _cl_context *context, struct _cl_event *event, GLbitfield flags) \
x(void, glClampColorARB, PFNGLCLAMPCOLORARBPROC, GLenum target, GLenum clamp) \
x(void, glDispatchComputeGroupSizeARB, PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC, GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z) \
x(void, glDebugMessageControlARB, PFNGLDEBUGMESSAGECONTROLARBPROC, GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) \
x(void, glDebugMessageInsertARB, PFNGLDEBUGMESSAGEINSERTARBPROC, GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf) \
x(void, glDebugMessageCallbackARB, PFNGLDEBUGMESSAGECALLBACKARBPROC, GLDEBUGPROCARB callback, const void *userParam) \
x(GLuint, glGetDebugMessageLogARB, PFNGLGETDEBUGMESSAGELOGARBPROC, GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog) \
x(void, glDrawBuffersARB, PFNGLDRAWBUFFERSARBPROC, GLsizei n, const GLenum *bufs) \
x(void, glBlendEquationiARB, PFNGLBLENDEQUATIONIARBPROC, GLuint buf, GLenum mode) \
x(void, glBlendEquationSeparateiARB, PFNGLBLENDEQUATIONSEPARATEIARBPROC, GLuint buf, GLenum modeRGB, GLenum modeAlpha) \
x(void, glBlendFunciARB, PFNGLBLENDFUNCIARBPROC, GLuint buf, GLenum src, GLenum dst) \
x(void, glBlendFuncSeparateiARB, PFNGLBLENDFUNCSEPARATEIARBPROC, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) \
x(void, glDrawArraysInstancedARB, PFNGLDRAWARRAYSINSTANCEDARBPROC, GLenum mode, GLint first, GLsizei count, GLsizei primcount) \
x(void, glDrawElementsInstancedARB, PFNGLDRAWELEMENTSINSTANCEDARBPROC, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount) \
x(void, glProgramStringARB, PFNGLPROGRAMSTRINGARBPROC, GLenum target, GLenum format, GLsizei len, const void *string) \
x(void, glBindProgramARB, PFNGLBINDPROGRAMARBPROC, GLenum target, GLuint program) \
x(void, glDeleteProgramsARB, PFNGLDELETEPROGRAMSARBPROC, GLsizei n, const GLuint *programs) \
x(void, glGenProgramsARB, PFNGLGENPROGRAMSARBPROC, GLsizei n, GLuint *programs) \
x(void, glProgramEnvParameter4dARB, PFNGLPROGRAMENVPARAMETER4DARBPROC, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glProgramEnvParameter4dvARB, PFNGLPROGRAMENVPARAMETER4DVARBPROC, GLenum target, GLuint index, const GLdouble *params) \
x(void, glProgramEnvParameter4fARB, PFNGLPROGRAMENVPARAMETER4FARBPROC, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glProgramEnvParameter4fvARB, PFNGLPROGRAMENVPARAMETER4FVARBPROC, GLenum target, GLuint index, const GLfloat *params) \
x(void, glProgramLocalParameter4dARB, PFNGLPROGRAMLOCALPARAMETER4DARBPROC, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glProgramLocalParameter4dvARB, PFNGLPROGRAMLOCALPARAMETER4DVARBPROC, GLenum target, GLuint index, const GLdouble *params) \
x(void, glProgramLocalParameter4fARB, PFNGLPROGRAMLOCALPARAMETER4FARBPROC, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glProgramLocalParameter4fvARB, PFNGLPROGRAMLOCALPARAMETER4FVARBPROC, GLenum target, GLuint index, const GLfloat *params) \
x(void, glGetProgramEnvParameterdvARB, PFNGLGETPROGRAMENVPARAMETERDVARBPROC, GLenum target, GLuint index, GLdouble *params) \
x(void, glGetProgramEnvParameterfvARB, PFNGLGETPROGRAMENVPARAMETERFVARBPROC, GLenum target, GLuint index, GLfloat *params) \
x(void, glGetProgramLocalParameterdvARB, PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC, GLenum target, GLuint index, GLdouble *params) \
x(void, glGetProgramLocalParameterfvARB, PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC, GLenum target, GLuint index, GLfloat *params) \
x(void, glGetProgramivARB, PFNGLGETPROGRAMIVARBPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetProgramStringARB, PFNGLGETPROGRAMSTRINGARBPROC, GLenum target, GLenum pname, void *string) \
x(GLboolean, glIsProgramARB, PFNGLISPROGRAMARBPROC, GLuint program) \
x(void, glProgramParameteriARB, PFNGLPROGRAMPARAMETERIARBPROC, GLuint program, GLenum pname, GLint value) \
x(void, glFramebufferTextureARB, PFNGLFRAMEBUFFERTEXTUREARBPROC, GLenum target, GLenum attachment, GLuint texture, GLint level) \
x(void, glFramebufferTextureLayerARB, PFNGLFRAMEBUFFERTEXTURELAYERARBPROC, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) \
x(void, glFramebufferTextureFaceARB, PFNGLFRAMEBUFFERTEXTUREFACEARBPROC, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) \
x(void, glSpecializeShaderARB, PFNGLSPECIALIZESHADERARBPROC, GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue) \
x(void, glUniform1i64ARB, PFNGLUNIFORM1I64ARBPROC, GLint location, GLint64 x) \
x(void, glUniform2i64ARB, PFNGLUNIFORM2I64ARBPROC, GLint location, GLint64 x, GLint64 y) \
x(void, glUniform3i64ARB, PFNGLUNIFORM3I64ARBPROC, GLint location, GLint64 x, GLint64 y, GLint64 z) \
x(void, glUniform4i64ARB, PFNGLUNIFORM4I64ARBPROC, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) \
x(void, glUniform1i64vARB, PFNGLUNIFORM1I64VARBPROC, GLint location, GLsizei count, const GLint64 *value) \
x(void, glUniform2i64vARB, PFNGLUNIFORM2I64VARBPROC, GLint location, GLsizei count, const GLint64 *value) \
x(void, glUniform3i64vARB, PFNGLUNIFORM3I64VARBPROC, GLint location, GLsizei count, const GLint64 *value) \
x(void, glUniform4i64vARB, PFNGLUNIFORM4I64VARBPROC, GLint location, GLsizei count, const GLint64 *value) \
x(void, glUniform1ui64ARB, PFNGLUNIFORM1UI64ARBPROC, GLint location, GLuint64 x) \
x(void, glUniform2ui64ARB, PFNGLUNIFORM2UI64ARBPROC, GLint location, GLuint64 x, GLuint64 y) \
x(void, glUniform3ui64ARB, PFNGLUNIFORM3UI64ARBPROC, GLint location, GLuint64 x, GLuint64 y, GLuint64 z) \
x(void, glUniform4ui64ARB, PFNGLUNIFORM4UI64ARBPROC, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) \
x(void, glUniform1ui64vARB, PFNGLUNIFORM1UI64VARBPROC, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glUniform2ui64vARB, PFNGLUNIFORM2UI64VARBPROC, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glUniform3ui64vARB, PFNGLUNIFORM3UI64VARBPROC, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glUniform4ui64vARB, PFNGLUNIFORM4UI64VARBPROC, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glGetUniformi64vARB, PFNGLGETUNIFORMI64VARBPROC, GLuint program, GLint location, GLint64 *params) \
x(void, glGetUniformui64vARB, PFNGLGETUNIFORMUI64VARBPROC, GLuint program, GLint location, GLuint64 *params) \
x(void, glGetnUniformi64vARB, PFNGLGETNUNIFORMI64VARBPROC, GLuint program, GLint location, GLsizei bufSize, GLint64 *params) \
x(void, glGetnUniformui64vARB, PFNGLGETNUNIFORMUI64VARBPROC, GLuint program, GLint location, GLsizei bufSize, GLuint64 *params) \
x(void, glProgramUniform1i64ARB, PFNGLPROGRAMUNIFORM1I64ARBPROC, GLuint program, GLint location, GLint64 x) \
x(void, glProgramUniform2i64ARB, PFNGLPROGRAMUNIFORM2I64ARBPROC, GLuint program, GLint location, GLint64 x, GLint64 y) \
x(void, glProgramUniform3i64ARB, PFNGLPROGRAMUNIFORM3I64ARBPROC, GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z) \
x(void, glProgramUniform4i64ARB, PFNGLPROGRAMUNIFORM4I64ARBPROC, GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w) \
x(void, glProgramUniform1i64vARB, PFNGLPROGRAMUNIFORM1I64VARBPROC, GLuint program, GLint location, GLsizei count, const GLint64 *value) \
x(void, glProgramUniform2i64vARB, PFNGLPROGRAMUNIFORM2I64VARBPROC, GLuint program, GLint location, GLsizei count, const GLint64 *value) \
x(void, glProgramUniform3i64vARB, PFNGLPROGRAMUNIFORM3I64VARBPROC, GLuint program, GLint location, GLsizei count, const GLint64 *value) \
x(void, glProgramUniform4i64vARB, PFNGLPROGRAMUNIFORM4I64VARBPROC, GLuint program, GLint location, GLsizei count, const GLint64 *value) \
x(void, glProgramUniform1ui64ARB, PFNGLPROGRAMUNIFORM1UI64ARBPROC, GLuint program, GLint location, GLuint64 x) \
x(void, glProgramUniform2ui64ARB, PFNGLPROGRAMUNIFORM2UI64ARBPROC, GLuint program, GLint location, GLuint64 x, GLuint64 y) \
x(void, glProgramUniform3ui64ARB, PFNGLPROGRAMUNIFORM3UI64ARBPROC, GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z) \
x(void, glProgramUniform4ui64ARB, PFNGLPROGRAMUNIFORM4UI64ARBPROC, GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w) \
x(void, glProgramUniform1ui64vARB, PFNGLPROGRAMUNIFORM1UI64VARBPROC, GLuint program, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glProgramUniform2ui64vARB, PFNGLPROGRAMUNIFORM2UI64VARBPROC, GLuint program, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glProgramUniform3ui64vARB, PFNGLPROGRAMUNIFORM3UI64VARBPROC, GLuint program, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glProgramUniform4ui64vARB, PFNGLPROGRAMUNIFORM4UI64VARBPROC, GLuint program, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glColorTable, PFNGLCOLORTABLEPROC, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table) \
x(void, glColorTableParameterfv, PFNGLCOLORTABLEPARAMETERFVPROC, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glColorTableParameteriv, PFNGLCOLORTABLEPARAMETERIVPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glCopyColorTable, PFNGLCOPYCOLORTABLEPROC, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) \
x(void, glGetColorTable, PFNGLGETCOLORTABLEPROC, GLenum target, GLenum format, GLenum type, void *table) \
x(void, glGetColorTableParameterfv, PFNGLGETCOLORTABLEPARAMETERFVPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetColorTableParameteriv, PFNGLGETCOLORTABLEPARAMETERIVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glColorSubTable, PFNGLCOLORSUBTABLEPROC, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data) \
x(void, glCopyColorSubTable, PFNGLCOPYCOLORSUBTABLEPROC, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) \
x(void, glConvolutionFilter1D, PFNGLCONVOLUTIONFILTER1DPROC, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image) \
x(void, glConvolutionFilter2D, PFNGLCONVOLUTIONFILTER2DPROC, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image) \
x(void, glConvolutionParameterf, PFNGLCONVOLUTIONPARAMETERFPROC, GLenum target, GLenum pname, GLfloat params) \
x(void, glConvolutionParameterfv, PFNGLCONVOLUTIONPARAMETERFVPROC, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glConvolutionParameteri, PFNGLCONVOLUTIONPARAMETERIPROC, GLenum target, GLenum pname, GLint params) \
x(void, glConvolutionParameteriv, PFNGLCONVOLUTIONPARAMETERIVPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glCopyConvolutionFilter1D, PFNGLCOPYCONVOLUTIONFILTER1DPROC, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) \
x(void, glCopyConvolutionFilter2D, PFNGLCOPYCONVOLUTIONFILTER2DPROC, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glGetConvolutionFilter, PFNGLGETCONVOLUTIONFILTERPROC, GLenum target, GLenum format, GLenum type, void *image) \
x(void, glGetConvolutionParameterfv, PFNGLGETCONVOLUTIONPARAMETERFVPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetConvolutionParameteriv, PFNGLGETCONVOLUTIONPARAMETERIVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetSeparableFilter, PFNGLGETSEPARABLEFILTERPROC, GLenum target, GLenum format, GLenum type, void *row, void *column, void *span) \
x(void, glSeparableFilter2D, PFNGLSEPARABLEFILTER2DPROC, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column) \
x(void, glGetHistogram, PFNGLGETHISTOGRAMPROC, GLenum target, GLboolean reset, GLenum format, GLenum type, void *values) \
x(void, glGetHistogramParameterfv, PFNGLGETHISTOGRAMPARAMETERFVPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetHistogramParameteriv, PFNGLGETHISTOGRAMPARAMETERIVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetMinmax, PFNGLGETMINMAXPROC, GLenum target, GLboolean reset, GLenum format, GLenum type, void *values) \
x(void, glGetMinmaxParameterfv, PFNGLGETMINMAXPARAMETERFVPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetMinmaxParameteriv, PFNGLGETMINMAXPARAMETERIVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glHistogram, PFNGLHISTOGRAMPROC, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) \
x(void, glMinmax, PFNGLMINMAXPROC, GLenum target, GLenum internalformat, GLboolean sink) \
x(void, glResetHistogram, PFNGLRESETHISTOGRAMPROC, GLenum target) \
x(void, glResetMinmax, PFNGLRESETMINMAXPROC, GLenum target) \
x(void, glMultiDrawArraysIndirectCountARB, PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC, GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) \
x(void, glMultiDrawElementsIndirectCountARB, PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC, GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) \
x(void, glVertexAttribDivisorARB, PFNGLVERTEXATTRIBDIVISORARBPROC, GLuint index, GLuint divisor) \
x(void, glCurrentPaletteMatrixARB, PFNGLCURRENTPALETTEMATRIXARBPROC, GLint index) \
x(void, glMatrixIndexubvARB, PFNGLMATRIXINDEXUBVARBPROC, GLint size, const GLubyte *indices) \
x(void, glMatrixIndexusvARB, PFNGLMATRIXINDEXUSVARBPROC, GLint size, const GLushort *indices) \
x(void, glMatrixIndexuivARB, PFNGLMATRIXINDEXUIVARBPROC, GLint size, const GLuint *indices) \
x(void, glMatrixIndexPointerARB, PFNGLMATRIXINDEXPOINTERARBPROC, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glSampleCoverageARB, PFNGLSAMPLECOVERAGEARBPROC, GLfloat value, GLboolean invert) \
x(void, glActiveTextureARB, PFNGLACTIVETEXTUREARBPROC, GLenum texture) \
x(void, glClientActiveTextureARB, PFNGLCLIENTACTIVETEXTUREARBPROC, GLenum texture) \
x(void, glMultiTexCoord1dARB, PFNGLMULTITEXCOORD1DARBPROC, GLenum target, GLdouble s) \
x(void, glMultiTexCoord1dvARB, PFNGLMULTITEXCOORD1DVARBPROC, GLenum target, const GLdouble *v) \
x(void, glMultiTexCoord1fARB, PFNGLMULTITEXCOORD1FARBPROC, GLenum target, GLfloat s) \
x(void, glMultiTexCoord1fvARB, PFNGLMULTITEXCOORD1FVARBPROC, GLenum target, const GLfloat *v) \
x(void, glMultiTexCoord1iARB, PFNGLMULTITEXCOORD1IARBPROC, GLenum target, GLint s) \
x(void, glMultiTexCoord1ivARB, PFNGLMULTITEXCOORD1IVARBPROC, GLenum target, const GLint *v) \
x(void, glMultiTexCoord1sARB, PFNGLMULTITEXCOORD1SARBPROC, GLenum target, GLshort s) \
x(void, glMultiTexCoord1svARB, PFNGLMULTITEXCOORD1SVARBPROC, GLenum target, const GLshort *v) \
x(void, glMultiTexCoord2dARB, PFNGLMULTITEXCOORD2DARBPROC, GLenum target, GLdouble s, GLdouble t) \
x(void, glMultiTexCoord2dvARB, PFNGLMULTITEXCOORD2DVARBPROC, GLenum target, const GLdouble *v) \
x(void, glMultiTexCoord2fARB, PFNGLMULTITEXCOORD2FARBPROC, GLenum target, GLfloat s, GLfloat t) \
x(void, glMultiTexCoord2fvARB, PFNGLMULTITEXCOORD2FVARBPROC, GLenum target, const GLfloat *v) \
x(void, glMultiTexCoord2iARB, PFNGLMULTITEXCOORD2IARBPROC, GLenum target, GLint s, GLint t) \
x(void, glMultiTexCoord2ivARB, PFNGLMULTITEXCOORD2IVARBPROC, GLenum target, const GLint *v) \
x(void, glMultiTexCoord2sARB, PFNGLMULTITEXCOORD2SARBPROC, GLenum target, GLshort s, GLshort t) \
x(void, glMultiTexCoord2svARB, PFNGLMULTITEXCOORD2SVARBPROC, GLenum target, const GLshort *v) \
x(void, glMultiTexCoord3dARB, PFNGLMULTITEXCOORD3DARBPROC, GLenum target, GLdouble s, GLdouble t, GLdouble r) \
x(void, glMultiTexCoord3dvARB, PFNGLMULTITEXCOORD3DVARBPROC, GLenum target, const GLdouble *v) \
x(void, glMultiTexCoord3fARB, PFNGLMULTITEXCOORD3FARBPROC, GLenum target, GLfloat s, GLfloat t, GLfloat r) \
x(void, glMultiTexCoord3fvARB, PFNGLMULTITEXCOORD3FVARBPROC, GLenum target, const GLfloat *v) \
x(void, glMultiTexCoord3iARB, PFNGLMULTITEXCOORD3IARBPROC, GLenum target, GLint s, GLint t, GLint r) \
x(void, glMultiTexCoord3ivARB, PFNGLMULTITEXCOORD3IVARBPROC, GLenum target, const GLint *v) \
x(void, glMultiTexCoord3sARB, PFNGLMULTITEXCOORD3SARBPROC, GLenum target, GLshort s, GLshort t, GLshort r) \
x(void, glMultiTexCoord3svARB, PFNGLMULTITEXCOORD3SVARBPROC, GLenum target, const GLshort *v) \
x(void, glMultiTexCoord4dARB, PFNGLMULTITEXCOORD4DARBPROC, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) \
x(void, glMultiTexCoord4dvARB, PFNGLMULTITEXCOORD4DVARBPROC, GLenum target, const GLdouble *v) \
x(void, glMultiTexCoord4fARB, PFNGLMULTITEXCOORD4FARBPROC, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) \
x(void, glMultiTexCoord4fvARB, PFNGLMULTITEXCOORD4FVARBPROC, GLenum target, const GLfloat *v) \
x(void, glMultiTexCoord4iARB, PFNGLMULTITEXCOORD4IARBPROC, GLenum target, GLint s, GLint t, GLint r, GLint q) \
x(void, glMultiTexCoord4ivARB, PFNGLMULTITEXCOORD4IVARBPROC, GLenum target, const GLint *v) \
x(void, glMultiTexCoord4sARB, PFNGLMULTITEXCOORD4SARBPROC, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) \
x(void, glMultiTexCoord4svARB, PFNGLMULTITEXCOORD4SVARBPROC, GLenum target, const GLshort *v) \
x(void, glGenQueriesARB, PFNGLGENQUERIESARBPROC, GLsizei n, GLuint *ids) \
x(void, glDeleteQueriesARB, PFNGLDELETEQUERIESARBPROC, GLsizei n, const GLuint *ids) \
x(GLboolean, glIsQueryARB, PFNGLISQUERYARBPROC, GLuint id) \
x(void, glBeginQueryARB, PFNGLBEGINQUERYARBPROC, GLenum target, GLuint id) \
x(void, glEndQueryARB, PFNGLENDQUERYARBPROC, GLenum target) \
x(void, glGetQueryivARB, PFNGLGETQUERYIVARBPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetQueryObjectivARB, PFNGLGETQUERYOBJECTIVARBPROC, GLuint id, GLenum pname, GLint *params) \
x(void, glGetQueryObjectuivARB, PFNGLGETQUERYOBJECTUIVARBPROC, GLuint id, GLenum pname, GLuint *params) \
x(void, glMaxShaderCompilerThreadsARB, PFNGLMAXSHADERCOMPILERTHREADSARBPROC, GLuint count) \
x(void, glPointParameterfARB, PFNGLPOINTPARAMETERFARBPROC, GLenum pname, GLfloat param) \
x(void, glPointParameterfvARB, PFNGLPOINTPARAMETERFVARBPROC, GLenum pname, const GLfloat *params) \
x(GLenum, glGetGraphicsResetStatusARB, PFNGLGETGRAPHICSRESETSTATUSARBPROC, void) \
x(void, glGetnTexImageARB, PFNGLGETNTEXIMAGEARBPROC, GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img) \
x(void, glReadnPixelsARB, PFNGLREADNPIXELSARBPROC, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data) \
x(void, glGetnCompressedTexImageARB, PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC, GLenum target, GLint lod, GLsizei bufSize, void *img) \
x(void, glGetnUniformfvARB, PFNGLGETNUNIFORMFVARBPROC, GLuint program, GLint location, GLsizei bufSize, GLfloat *params) \
x(void, glGetnUniformivARB, PFNGLGETNUNIFORMIVARBPROC, GLuint program, GLint location, GLsizei bufSize, GLint *params) \
x(void, glGetnUniformuivARB, PFNGLGETNUNIFORMUIVARBPROC, GLuint program, GLint location, GLsizei bufSize, GLuint *params) \
x(void, glGetnUniformdvARB, PFNGLGETNUNIFORMDVARBPROC, GLuint program, GLint location, GLsizei bufSize, GLdouble *params) \
x(void, glGetnMapdvARB, PFNGLGETNMAPDVARBPROC, GLenum target, GLenum query, GLsizei bufSize, GLdouble *v) \
x(void, glGetnMapfvARB, PFNGLGETNMAPFVARBPROC, GLenum target, GLenum query, GLsizei bufSize, GLfloat *v) \
x(void, glGetnMapivARB, PFNGLGETNMAPIVARBPROC, GLenum target, GLenum query, GLsizei bufSize, GLint *v) \
x(void, glGetnPixelMapfvARB, PFNGLGETNPIXELMAPFVARBPROC, GLenum map, GLsizei bufSize, GLfloat *values) \
x(void, glGetnPixelMapuivARB, PFNGLGETNPIXELMAPUIVARBPROC, GLenum map, GLsizei bufSize, GLuint *values) \
x(void, glGetnPixelMapusvARB, PFNGLGETNPIXELMAPUSVARBPROC, GLenum map, GLsizei bufSize, GLushort *values) \
x(void, glGetnPolygonStippleARB, PFNGLGETNPOLYGONSTIPPLEARBPROC, GLsizei bufSize, GLubyte *pattern) \
x(void, glGetnColorTableARB, PFNGLGETNCOLORTABLEARBPROC, GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table) \
x(void, glGetnConvolutionFilterARB, PFNGLGETNCONVOLUTIONFILTERARBPROC, GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image) \
x(void, glGetnSeparableFilterARB, PFNGLGETNSEPARABLEFILTERARBPROC, GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span) \
x(void, glGetnHistogramARB, PFNGLGETNHISTOGRAMARBPROC, GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) \
x(void, glGetnMinmaxARB, PFNGLGETNMINMAXARBPROC, GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values) \
x(void, glFramebufferSampleLocationsfvARB, PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC, GLenum target, GLuint start, GLsizei count, const GLfloat *v) \
x(void, glNamedFramebufferSampleLocationsfvARB, PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v) \
x(void, glEvaluateDepthValuesARB, PFNGLEVALUATEDEPTHVALUESARBPROC, void) \
x(void, glMinSampleShadingARB, PFNGLMINSAMPLESHADINGARBPROC, GLfloat value) \
x(void, glDeleteObjectARB, PFNGLDELETEOBJECTARBPROC, GLhandleARB obj) \
x(GLhandleARB, glGetHandleARB, PFNGLGETHANDLEARBPROC, GLenum pname) \
x(void, glDetachObjectARB, PFNGLDETACHOBJECTARBPROC, GLhandleARB containerObj, GLhandleARB attachedObj) \
x(GLhandleARB, glCreateShaderObjectARB, PFNGLCREATESHADEROBJECTARBPROC, GLenum shaderType) \
x(void, glShaderSourceARB, PFNGLSHADERSOURCEARBPROC, GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length) \
x(void, glCompileShaderARB, PFNGLCOMPILESHADERARBPROC, GLhandleARB shaderObj) \
x(GLhandleARB, glCreateProgramObjectARB, PFNGLCREATEPROGRAMOBJECTARBPROC, void) \
x(void, glAttachObjectARB, PFNGLATTACHOBJECTARBPROC, GLhandleARB containerObj, GLhandleARB obj) \
x(void, glLinkProgramARB, PFNGLLINKPROGRAMARBPROC, GLhandleARB programObj) \
x(void, glUseProgramObjectARB, PFNGLUSEPROGRAMOBJECTARBPROC, GLhandleARB programObj) \
x(void, glValidateProgramARB, PFNGLVALIDATEPROGRAMARBPROC, GLhandleARB programObj) \
x(void, glUniform1fARB, PFNGLUNIFORM1FARBPROC, GLint location, GLfloat v0) \
x(void, glUniform2fARB, PFNGLUNIFORM2FARBPROC, GLint location, GLfloat v0, GLfloat v1) \
x(void, glUniform3fARB, PFNGLUNIFORM3FARBPROC, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) \
x(void, glUniform4fARB, PFNGLUNIFORM4FARBPROC, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) \
x(void, glUniform1iARB, PFNGLUNIFORM1IARBPROC, GLint location, GLint v0) \
x(void, glUniform2iARB, PFNGLUNIFORM2IARBPROC, GLint location, GLint v0, GLint v1) \
x(void, glUniform3iARB, PFNGLUNIFORM3IARBPROC, GLint location, GLint v0, GLint v1, GLint v2) \
x(void, glUniform4iARB, PFNGLUNIFORM4IARBPROC, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) \
x(void, glUniform1fvARB, PFNGLUNIFORM1FVARBPROC, GLint location, GLsizei count, const GLfloat *value) \
x(void, glUniform2fvARB, PFNGLUNIFORM2FVARBPROC, GLint location, GLsizei count, const GLfloat *value) \
x(void, glUniform3fvARB, PFNGLUNIFORM3FVARBPROC, GLint location, GLsizei count, const GLfloat *value) \
x(void, glUniform4fvARB, PFNGLUNIFORM4FVARBPROC, GLint location, GLsizei count, const GLfloat *value) \
x(void, glUniform1ivARB, PFNGLUNIFORM1IVARBPROC, GLint location, GLsizei count, const GLint *value) \
x(void, glUniform2ivARB, PFNGLUNIFORM2IVARBPROC, GLint location, GLsizei count, const GLint *value) \
x(void, glUniform3ivARB, PFNGLUNIFORM3IVARBPROC, GLint location, GLsizei count, const GLint *value) \
x(void, glUniform4ivARB, PFNGLUNIFORM4IVARBPROC, GLint location, GLsizei count, const GLint *value) \
x(void, glUniformMatrix2fvARB, PFNGLUNIFORMMATRIX2FVARBPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix3fvARB, PFNGLUNIFORMMATRIX3FVARBPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glUniformMatrix4fvARB, PFNGLUNIFORMMATRIX4FVARBPROC, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glGetObjectParameterfvARB, PFNGLGETOBJECTPARAMETERFVARBPROC, GLhandleARB obj, GLenum pname, GLfloat *params) \
x(void, glGetObjectParameterivARB, PFNGLGETOBJECTPARAMETERIVARBPROC, GLhandleARB obj, GLenum pname, GLint *params) \
x(void, glGetInfoLogARB, PFNGLGETINFOLOGARBPROC, GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog) \
x(void, glGetAttachedObjectsARB, PFNGLGETATTACHEDOBJECTSARBPROC, GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj) \
x(GLint, glGetUniformLocationARB, PFNGLGETUNIFORMLOCATIONARBPROC, GLhandleARB programObj, const GLcharARB *name) \
x(void, glGetActiveUniformARB, PFNGLGETACTIVEUNIFORMARBPROC, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name) \
x(void, glGetUniformfvARB, PFNGLGETUNIFORMFVARBPROC, GLhandleARB programObj, GLint location, GLfloat *params) \
x(void, glGetUniformivARB, PFNGLGETUNIFORMIVARBPROC, GLhandleARB programObj, GLint location, GLint *params) \
x(void, glGetShaderSourceARB, PFNGLGETSHADERSOURCEARBPROC, GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source) \
x(void, glNamedStringARB, PFNGLNAMEDSTRINGARBPROC, GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string) \
x(void, glDeleteNamedStringARB, PFNGLDELETENAMEDSTRINGARBPROC, GLint namelen, const GLchar *name) \
x(void, glCompileShaderIncludeARB, PFNGLCOMPILESHADERINCLUDEARBPROC, GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length) \
x(GLboolean, glIsNamedStringARB, PFNGLISNAMEDSTRINGARBPROC, GLint namelen, const GLchar *name) \
x(void, glGetNamedStringARB, PFNGLGETNAMEDSTRINGARBPROC, GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string) \
x(void, glGetNamedStringivARB, PFNGLGETNAMEDSTRINGIVARBPROC, GLint namelen, const GLchar *name, GLenum pname, GLint *params) \
x(void, glBufferPageCommitmentARB, PFNGLBUFFERPAGECOMMITMENTARBPROC, GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit) \
x(void, glNamedBufferPageCommitmentEXT, PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC, GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) \
x(void, glNamedBufferPageCommitmentARB, PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC, GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit) \
x(void, glTexPageCommitmentARB, PFNGLTEXPAGECOMMITMENTARBPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) \
x(void, glTexBufferARB, PFNGLTEXBUFFERARBPROC, GLenum target, GLenum internalformat, GLuint buffer) \
x(void, glCompressedTexImage3DARB, PFNGLCOMPRESSEDTEXIMAGE3DARBPROC, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data) \
x(void, glCompressedTexImage2DARB, PFNGLCOMPRESSEDTEXIMAGE2DARBPROC, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) \
x(void, glCompressedTexImage1DARB, PFNGLCOMPRESSEDTEXIMAGE1DARBPROC, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data) \
x(void, glCompressedTexSubImage3DARB, PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data) \
x(void, glCompressedTexSubImage2DARB, PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data) \
x(void, glCompressedTexSubImage1DARB, PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data) \
x(void, glGetCompressedTexImageARB, PFNGLGETCOMPRESSEDTEXIMAGEARBPROC, GLenum target, GLint level, void *img) \
x(void, glLoadTransposeMatrixfARB, PFNGLLOADTRANSPOSEMATRIXFARBPROC, const GLfloat *m) \
x(void, glLoadTransposeMatrixdARB, PFNGLLOADTRANSPOSEMATRIXDARBPROC, const GLdouble *m) \
x(void, glMultTransposeMatrixfARB, PFNGLMULTTRANSPOSEMATRIXFARBPROC, const GLfloat *m) \
x(void, glMultTransposeMatrixdARB, PFNGLMULTTRANSPOSEMATRIXDARBPROC, const GLdouble *m) \
x(void, glWeightbvARB, PFNGLWEIGHTBVARBPROC, GLint size, const GLbyte *weights) \
x(void, glWeightsvARB, PFNGLWEIGHTSVARBPROC, GLint size, const GLshort *weights) \
x(void, glWeightivARB, PFNGLWEIGHTIVARBPROC, GLint size, const GLint *weights) \
x(void, glWeightfvARB, PFNGLWEIGHTFVARBPROC, GLint size, const GLfloat *weights) \
x(void, glWeightdvARB, PFNGLWEIGHTDVARBPROC, GLint size, const GLdouble *weights) \
x(void, glWeightubvARB, PFNGLWEIGHTUBVARBPROC, GLint size, const GLubyte *weights) \
x(void, glWeightusvARB, PFNGLWEIGHTUSVARBPROC, GLint size, const GLushort *weights) \
x(void, glWeightuivARB, PFNGLWEIGHTUIVARBPROC, GLint size, const GLuint *weights) \
x(void, glWeightPointerARB, PFNGLWEIGHTPOINTERARBPROC, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glVertexBlendARB, PFNGLVERTEXBLENDARBPROC, GLint count) \
x(void, glBindBufferARB, PFNGLBINDBUFFERARBPROC, GLenum target, GLuint buffer) \
x(void, glDeleteBuffersARB, PFNGLDELETEBUFFERSARBPROC, GLsizei n, const GLuint *buffers) \
x(void, glGenBuffersARB, PFNGLGENBUFFERSARBPROC, GLsizei n, GLuint *buffers) \
x(GLboolean, glIsBufferARB, PFNGLISBUFFERARBPROC, GLuint buffer) \
x(void, glBufferDataARB, PFNGLBUFFERDATAARBPROC, GLenum target, GLsizeiptrARB size, const void *data, GLenum usage) \
x(void, glBufferSubDataARB, PFNGLBUFFERSUBDATAARBPROC, GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void *data) \
x(void, glGetBufferSubDataARB, PFNGLGETBUFFERSUBDATAARBPROC, GLenum target, GLintptrARB offset, GLsizeiptrARB size, void *data) \
x(GLboolean, glUnmapBufferARB, PFNGLUNMAPBUFFERARBPROC, GLenum target) \
x(void, glGetBufferParameterivARB, PFNGLGETBUFFERPARAMETERIVARBPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetBufferPointervARB, PFNGLGETBUFFERPOINTERVARBPROC, GLenum target, GLenum pname, void **params) \
x(void, glVertexAttrib1dARB, PFNGLVERTEXATTRIB1DARBPROC, GLuint index, GLdouble x) \
x(void, glVertexAttrib1dvARB, PFNGLVERTEXATTRIB1DVARBPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib1fARB, PFNGLVERTEXATTRIB1FARBPROC, GLuint index, GLfloat x) \
x(void, glVertexAttrib1fvARB, PFNGLVERTEXATTRIB1FVARBPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib1sARB, PFNGLVERTEXATTRIB1SARBPROC, GLuint index, GLshort x) \
x(void, glVertexAttrib1svARB, PFNGLVERTEXATTRIB1SVARBPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib2dARB, PFNGLVERTEXATTRIB2DARBPROC, GLuint index, GLdouble x, GLdouble y) \
x(void, glVertexAttrib2dvARB, PFNGLVERTEXATTRIB2DVARBPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib2fARB, PFNGLVERTEXATTRIB2FARBPROC, GLuint index, GLfloat x, GLfloat y) \
x(void, glVertexAttrib2fvARB, PFNGLVERTEXATTRIB2FVARBPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib2sARB, PFNGLVERTEXATTRIB2SARBPROC, GLuint index, GLshort x, GLshort y) \
x(void, glVertexAttrib2svARB, PFNGLVERTEXATTRIB2SVARBPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib3dARB, PFNGLVERTEXATTRIB3DARBPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z) \
x(void, glVertexAttrib3dvARB, PFNGLVERTEXATTRIB3DVARBPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib3fARB, PFNGLVERTEXATTRIB3FARBPROC, GLuint index, GLfloat x, GLfloat y, GLfloat z) \
x(void, glVertexAttrib3fvARB, PFNGLVERTEXATTRIB3FVARBPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib3sARB, PFNGLVERTEXATTRIB3SARBPROC, GLuint index, GLshort x, GLshort y, GLshort z) \
x(void, glVertexAttrib3svARB, PFNGLVERTEXATTRIB3SVARBPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib4NbvARB, PFNGLVERTEXATTRIB4NBVARBPROC, GLuint index, const GLbyte *v) \
x(void, glVertexAttrib4NivARB, PFNGLVERTEXATTRIB4NIVARBPROC, GLuint index, const GLint *v) \
x(void, glVertexAttrib4NsvARB, PFNGLVERTEXATTRIB4NSVARBPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib4NubARB, PFNGLVERTEXATTRIB4NUBARBPROC, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) \
x(void, glVertexAttrib4NubvARB, PFNGLVERTEXATTRIB4NUBVARBPROC, GLuint index, const GLubyte *v) \
x(void, glVertexAttrib4NuivARB, PFNGLVERTEXATTRIB4NUIVARBPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttrib4NusvARB, PFNGLVERTEXATTRIB4NUSVARBPROC, GLuint index, const GLushort *v) \
x(void, glVertexAttrib4bvARB, PFNGLVERTEXATTRIB4BVARBPROC, GLuint index, const GLbyte *v) \
x(void, glVertexAttrib4dARB, PFNGLVERTEXATTRIB4DARBPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glVertexAttrib4dvARB, PFNGLVERTEXATTRIB4DVARBPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib4fARB, PFNGLVERTEXATTRIB4FARBPROC, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glVertexAttrib4fvARB, PFNGLVERTEXATTRIB4FVARBPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib4ivARB, PFNGLVERTEXATTRIB4IVARBPROC, GLuint index, const GLint *v) \
x(void, glVertexAttrib4sARB, PFNGLVERTEXATTRIB4SARBPROC, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) \
x(void, glVertexAttrib4svARB, PFNGLVERTEXATTRIB4SVARBPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib4ubvARB, PFNGLVERTEXATTRIB4UBVARBPROC, GLuint index, const GLubyte *v) \
x(void, glVertexAttrib4uivARB, PFNGLVERTEXATTRIB4UIVARBPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttrib4usvARB, PFNGLVERTEXATTRIB4USVARBPROC, GLuint index, const GLushort *v) \
x(void, glVertexAttribPointerARB, PFNGLVERTEXATTRIBPOINTERARBPROC, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) \
x(void, glEnableVertexAttribArrayARB, PFNGLENABLEVERTEXATTRIBARRAYARBPROC, GLuint index) \
x(void, glDisableVertexAttribArrayARB, PFNGLDISABLEVERTEXATTRIBARRAYARBPROC, GLuint index) \
x(void, glGetVertexAttribdvARB, PFNGLGETVERTEXATTRIBDVARBPROC, GLuint index, GLenum pname, GLdouble *params) \
x(void, glGetVertexAttribfvARB, PFNGLGETVERTEXATTRIBFVARBPROC, GLuint index, GLenum pname, GLfloat *params) \
x(void, glGetVertexAttribivARB, PFNGLGETVERTEXATTRIBIVARBPROC, GLuint index, GLenum pname, GLint *params) \
x(void, glGetVertexAttribPointervARB, PFNGLGETVERTEXATTRIBPOINTERVARBPROC, GLuint index, GLenum pname, void **pointer) \
x(void, glBindAttribLocationARB, PFNGLBINDATTRIBLOCATIONARBPROC, GLhandleARB programObj, GLuint index, const GLcharARB *name) \
x(void, glGetActiveAttribARB, PFNGLGETACTIVEATTRIBARBPROC, GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name) \
x(GLint, glGetAttribLocationARB, PFNGLGETATTRIBLOCATIONARBPROC, GLhandleARB programObj, const GLcharARB *name) \
x(void, glDepthRangeArraydvNV, PFNGLDEPTHRANGEARRAYDVNVPROC, GLuint first, GLsizei count, const GLdouble *v) \
x(void, glDepthRangeIndexeddNV, PFNGLDEPTHRANGEINDEXEDDNVPROC, GLuint index, GLdouble n, GLdouble f) \
x(void, glWindowPos2dARB, PFNGLWINDOWPOS2DARBPROC, GLdouble x, GLdouble y) \
x(void, glWindowPos2dvARB, PFNGLWINDOWPOS2DVARBPROC, const GLdouble *v) \
x(void, glWindowPos2fARB, PFNGLWINDOWPOS2FARBPROC, GLfloat x, GLfloat y) \
x(void, glWindowPos2fvARB, PFNGLWINDOWPOS2FVARBPROC, const GLfloat *v) \
x(void, glWindowPos2iARB, PFNGLWINDOWPOS2IARBPROC, GLint x, GLint y) \
x(void, glWindowPos2ivARB, PFNGLWINDOWPOS2IVARBPROC, const GLint *v) \
x(void, glWindowPos2sARB, PFNGLWINDOWPOS2SARBPROC, GLshort x, GLshort y) \
x(void, glWindowPos2svARB, PFNGLWINDOWPOS2SVARBPROC, const GLshort *v) \
x(void, glWindowPos3dARB, PFNGLWINDOWPOS3DARBPROC, GLdouble x, GLdouble y, GLdouble z) \
x(void, glWindowPos3dvARB, PFNGLWINDOWPOS3DVARBPROC, const GLdouble *v) \
x(void, glWindowPos3fARB, PFNGLWINDOWPOS3FARBPROC, GLfloat x, GLfloat y, GLfloat z) \
x(void, glWindowPos3fvARB, PFNGLWINDOWPOS3FVARBPROC, const GLfloat *v) \
x(void, glWindowPos3iARB, PFNGLWINDOWPOS3IARBPROC, GLint x, GLint y, GLint z) \
x(void, glWindowPos3ivARB, PFNGLWINDOWPOS3IVARBPROC, const GLint *v) \
x(void, glWindowPos3sARB, PFNGLWINDOWPOS3SARBPROC, GLshort x, GLshort y, GLshort z) \
x(void, glWindowPos3svARB, PFNGLWINDOWPOS3SVARBPROC, const GLshort *v) \
x(void, glBlendBarrierKHR, PFNGLBLENDBARRIERKHRPROC, void) \
x(void, glMaxShaderCompilerThreadsKHR, PFNGLMAXSHADERCOMPILERTHREADSKHRPROC, GLuint count) \
x(void, glMultiTexCoord1bOES, PFNGLMULTITEXCOORD1BOESPROC, GLenum texture, GLbyte s) \
x(void, glMultiTexCoord1bvOES, PFNGLMULTITEXCOORD1BVOESPROC, GLenum texture, const GLbyte *coords) \
x(void, glMultiTexCoord2bOES, PFNGLMULTITEXCOORD2BOESPROC, GLenum texture, GLbyte s, GLbyte t) \
x(void, glMultiTexCoord2bvOES, PFNGLMULTITEXCOORD2BVOESPROC, GLenum texture, const GLbyte *coords) \
x(void, glMultiTexCoord3bOES, PFNGLMULTITEXCOORD3BOESPROC, GLenum texture, GLbyte s, GLbyte t, GLbyte r) \
x(void, glMultiTexCoord3bvOES, PFNGLMULTITEXCOORD3BVOESPROC, GLenum texture, const GLbyte *coords) \
x(void, glMultiTexCoord4bOES, PFNGLMULTITEXCOORD4BOESPROC, GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q) \
x(void, glMultiTexCoord4bvOES, PFNGLMULTITEXCOORD4BVOESPROC, GLenum texture, const GLbyte *coords) \
x(void, glTexCoord1bOES, PFNGLTEXCOORD1BOESPROC, GLbyte s) \
x(void, glTexCoord1bvOES, PFNGLTEXCOORD1BVOESPROC, const GLbyte *coords) \
x(void, glTexCoord2bOES, PFNGLTEXCOORD2BOESPROC, GLbyte s, GLbyte t) \
x(void, glTexCoord2bvOES, PFNGLTEXCOORD2BVOESPROC, const GLbyte *coords) \
x(void, glTexCoord3bOES, PFNGLTEXCOORD3BOESPROC, GLbyte s, GLbyte t, GLbyte r) \
x(void, glTexCoord3bvOES, PFNGLTEXCOORD3BVOESPROC, const GLbyte *coords) \
x(void, glTexCoord4bOES, PFNGLTEXCOORD4BOESPROC, GLbyte s, GLbyte t, GLbyte r, GLbyte q) \
x(void, glTexCoord4bvOES, PFNGLTEXCOORD4BVOESPROC, const GLbyte *coords) \
x(void, glVertex2bOES, PFNGLVERTEX2BOESPROC, GLbyte x, GLbyte y) \
x(void, glVertex2bvOES, PFNGLVERTEX2BVOESPROC, const GLbyte *coords) \
x(void, glVertex3bOES, PFNGLVERTEX3BOESPROC, GLbyte x, GLbyte y, GLbyte z) \
x(void, glVertex3bvOES, PFNGLVERTEX3BVOESPROC, const GLbyte *coords) \
x(void, glVertex4bOES, PFNGLVERTEX4BOESPROC, GLbyte x, GLbyte y, GLbyte z, GLbyte w) \
x(void, glVertex4bvOES, PFNGLVERTEX4BVOESPROC, const GLbyte *coords) \
x(void, glAlphaFuncxOES, PFNGLALPHAFUNCXOESPROC, GLenum func, GLfixed ref) \
x(void, glClearColorxOES, PFNGLCLEARCOLORXOESPROC, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) \
x(void, glClearDepthxOES, PFNGLCLEARDEPTHXOESPROC, GLfixed depth) \
x(void, glClipPlanexOES, PFNGLCLIPPLANEXOESPROC, GLenum plane, const GLfixed *equation) \
x(void, glColor4xOES, PFNGLCOLOR4XOESPROC, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) \
x(void, glDepthRangexOES, PFNGLDEPTHRANGEXOESPROC, GLfixed n, GLfixed f) \
x(void, glFogxOES, PFNGLFOGXOESPROC, GLenum pname, GLfixed param) \
x(void, glFogxvOES, PFNGLFOGXVOESPROC, GLenum pname, const GLfixed *param) \
x(void, glFrustumxOES, PFNGLFRUSTUMXOESPROC, GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) \
x(void, glGetClipPlanexOES, PFNGLGETCLIPPLANEXOESPROC, GLenum plane, GLfixed *equation) \
x(void, glGetFixedvOES, PFNGLGETFIXEDVOESPROC, GLenum pname, GLfixed *params) \
x(void, glGetTexEnvxvOES, PFNGLGETTEXENVXVOESPROC, GLenum target, GLenum pname, GLfixed *params) \
x(void, glGetTexParameterxvOES, PFNGLGETTEXPARAMETERXVOESPROC, GLenum target, GLenum pname, GLfixed *params) \
x(void, glLightModelxOES, PFNGLLIGHTMODELXOESPROC, GLenum pname, GLfixed param) \
x(void, glLightModelxvOES, PFNGLLIGHTMODELXVOESPROC, GLenum pname, const GLfixed *param) \
x(void, glLightxOES, PFNGLLIGHTXOESPROC, GLenum light, GLenum pname, GLfixed param) \
x(void, glLightxvOES, PFNGLLIGHTXVOESPROC, GLenum light, GLenum pname, const GLfixed *params) \
x(void, glLineWidthxOES, PFNGLLINEWIDTHXOESPROC, GLfixed width) \
x(void, glLoadMatrixxOES, PFNGLLOADMATRIXXOESPROC, const GLfixed *m) \
x(void, glMaterialxOES, PFNGLMATERIALXOESPROC, GLenum face, GLenum pname, GLfixed param) \
x(void, glMaterialxvOES, PFNGLMATERIALXVOESPROC, GLenum face, GLenum pname, const GLfixed *param) \
x(void, glMultMatrixxOES, PFNGLMULTMATRIXXOESPROC, const GLfixed *m) \
x(void, glMultiTexCoord4xOES, PFNGLMULTITEXCOORD4XOESPROC, GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) \
x(void, glNormal3xOES, PFNGLNORMAL3XOESPROC, GLfixed nx, GLfixed ny, GLfixed nz) \
x(void, glOrthoxOES, PFNGLORTHOXOESPROC, GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) \
x(void, glPointParameterxvOES, PFNGLPOINTPARAMETERXVOESPROC, GLenum pname, const GLfixed *params) \
x(void, glPointSizexOES, PFNGLPOINTSIZEXOESPROC, GLfixed size) \
x(void, glPolygonOffsetxOES, PFNGLPOLYGONOFFSETXOESPROC, GLfixed factor, GLfixed units) \
x(void, glRotatexOES, PFNGLROTATEXOESPROC, GLfixed angle, GLfixed x, GLfixed y, GLfixed z) \
x(void, glScalexOES, PFNGLSCALEXOESPROC, GLfixed x, GLfixed y, GLfixed z) \
x(void, glTexEnvxOES, PFNGLTEXENVXOESPROC, GLenum target, GLenum pname, GLfixed param) \
x(void, glTexEnvxvOES, PFNGLTEXENVXVOESPROC, GLenum target, GLenum pname, const GLfixed *params) \
x(void, glTexParameterxOES, PFNGLTEXPARAMETERXOESPROC, GLenum target, GLenum pname, GLfixed param) \
x(void, glTexParameterxvOES, PFNGLTEXPARAMETERXVOESPROC, GLenum target, GLenum pname, const GLfixed *params) \
x(void, glTranslatexOES, PFNGLTRANSLATEXOESPROC, GLfixed x, GLfixed y, GLfixed z) \
x(void, glAccumxOES, PFNGLACCUMXOESPROC, GLenum op, GLfixed value) \
x(void, glBitmapxOES, PFNGLBITMAPXOESPROC, GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte *bitmap) \
x(void, glBlendColorxOES, PFNGLBLENDCOLORXOESPROC, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) \
x(void, glClearAccumxOES, PFNGLCLEARACCUMXOESPROC, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) \
x(void, glColor3xOES, PFNGLCOLOR3XOESPROC, GLfixed red, GLfixed green, GLfixed blue) \
x(void, glColor3xvOES, PFNGLCOLOR3XVOESPROC, const GLfixed *components) \
x(void, glColor4xvOES, PFNGLCOLOR4XVOESPROC, const GLfixed *components) \
x(void, glConvolutionParameterxOES, PFNGLCONVOLUTIONPARAMETERXOESPROC, GLenum target, GLenum pname, GLfixed param) \
x(void, glConvolutionParameterxvOES, PFNGLCONVOLUTIONPARAMETERXVOESPROC, GLenum target, GLenum pname, const GLfixed *params) \
x(void, glEvalCoord1xOES, PFNGLEVALCOORD1XOESPROC, GLfixed u) \
x(void, glEvalCoord1xvOES, PFNGLEVALCOORD1XVOESPROC, const GLfixed *coords) \
x(void, glEvalCoord2xOES, PFNGLEVALCOORD2XOESPROC, GLfixed u, GLfixed v) \
x(void, glEvalCoord2xvOES, PFNGLEVALCOORD2XVOESPROC, const GLfixed *coords) \
x(void, glFeedbackBufferxOES, PFNGLFEEDBACKBUFFERXOESPROC, GLsizei n, GLenum type, const GLfixed *buffer) \
x(void, glGetConvolutionParameterxvOES, PFNGLGETCONVOLUTIONPARAMETERXVOESPROC, GLenum target, GLenum pname, GLfixed *params) \
x(void, glGetHistogramParameterxvOES, PFNGLGETHISTOGRAMPARAMETERXVOESPROC, GLenum target, GLenum pname, GLfixed *params) \
x(void, glGetLightxOES, PFNGLGETLIGHTXOESPROC, GLenum light, GLenum pname, GLfixed *params) \
x(void, glGetMapxvOES, PFNGLGETMAPXVOESPROC, GLenum target, GLenum query, GLfixed *v) \
x(void, glGetMaterialxOES, PFNGLGETMATERIALXOESPROC, GLenum face, GLenum pname, GLfixed param) \
x(void, glGetPixelMapxv, PFNGLGETPIXELMAPXVPROC, GLenum map, GLint size, GLfixed *values) \
x(void, glGetTexGenxvOES, PFNGLGETTEXGENXVOESPROC, GLenum coord, GLenum pname, GLfixed *params) \
x(void, glGetTexLevelParameterxvOES, PFNGLGETTEXLEVELPARAMETERXVOESPROC, GLenum target, GLint level, GLenum pname, GLfixed *params) \
x(void, glIndexxOES, PFNGLINDEXXOESPROC, GLfixed component) \
x(void, glIndexxvOES, PFNGLINDEXXVOESPROC, const GLfixed *component) \
x(void, glLoadTransposeMatrixxOES, PFNGLLOADTRANSPOSEMATRIXXOESPROC, const GLfixed *m) \
x(void, glMap1xOES, PFNGLMAP1XOESPROC, GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points) \
x(void, glMap2xOES, PFNGLMAP2XOESPROC, GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points) \
x(void, glMapGrid1xOES, PFNGLMAPGRID1XOESPROC, GLint n, GLfixed u1, GLfixed u2) \
x(void, glMapGrid2xOES, PFNGLMAPGRID2XOESPROC, GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2) \
x(void, glMultTransposeMatrixxOES, PFNGLMULTTRANSPOSEMATRIXXOESPROC, const GLfixed *m) \
x(void, glMultiTexCoord1xOES, PFNGLMULTITEXCOORD1XOESPROC, GLenum texture, GLfixed s) \
x(void, glMultiTexCoord1xvOES, PFNGLMULTITEXCOORD1XVOESPROC, GLenum texture, const GLfixed *coords) \
x(void, glMultiTexCoord2xOES, PFNGLMULTITEXCOORD2XOESPROC, GLenum texture, GLfixed s, GLfixed t) \
x(void, glMultiTexCoord2xvOES, PFNGLMULTITEXCOORD2XVOESPROC, GLenum texture, const GLfixed *coords) \
x(void, glMultiTexCoord3xOES, PFNGLMULTITEXCOORD3XOESPROC, GLenum texture, GLfixed s, GLfixed t, GLfixed r) \
x(void, glMultiTexCoord3xvOES, PFNGLMULTITEXCOORD3XVOESPROC, GLenum texture, const GLfixed *coords) \
x(void, glMultiTexCoord4xvOES, PFNGLMULTITEXCOORD4XVOESPROC, GLenum texture, const GLfixed *coords) \
x(void, glNormal3xvOES, PFNGLNORMAL3XVOESPROC, const GLfixed *coords) \
x(void, glPassThroughxOES, PFNGLPASSTHROUGHXOESPROC, GLfixed token) \
x(void, glPixelMapx, PFNGLPIXELMAPXPROC, GLenum map, GLint size, const GLfixed *values) \
x(void, glPixelStorex, PFNGLPIXELSTOREXPROC, GLenum pname, GLfixed param) \
x(void, glPixelTransferxOES, PFNGLPIXELTRANSFERXOESPROC, GLenum pname, GLfixed param) \
x(void, glPixelZoomxOES, PFNGLPIXELZOOMXOESPROC, GLfixed xfactor, GLfixed yfactor) \
x(void, glPrioritizeTexturesxOES, PFNGLPRIORITIZETEXTURESXOESPROC, GLsizei n, const GLuint *textures, const GLfixed *priorities) \
x(void, glRasterPos2xOES, PFNGLRASTERPOS2XOESPROC, GLfixed x, GLfixed y) \
x(void, glRasterPos2xvOES, PFNGLRASTERPOS2XVOESPROC, const GLfixed *coords) \
x(void, glRasterPos3xOES, PFNGLRASTERPOS3XOESPROC, GLfixed x, GLfixed y, GLfixed z) \
x(void, glRasterPos3xvOES, PFNGLRASTERPOS3XVOESPROC, const GLfixed *coords) \
x(void, glRasterPos4xOES, PFNGLRASTERPOS4XOESPROC, GLfixed x, GLfixed y, GLfixed z, GLfixed w) \
x(void, glRasterPos4xvOES, PFNGLRASTERPOS4XVOESPROC, const GLfixed *coords) \
x(void, glRectxOES, PFNGLRECTXOESPROC, GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2) \
x(void, glRectxvOES, PFNGLRECTXVOESPROC, const GLfixed *v1, const GLfixed *v2) \
x(void, glTexCoord1xOES, PFNGLTEXCOORD1XOESPROC, GLfixed s) \
x(void, glTexCoord1xvOES, PFNGLTEXCOORD1XVOESPROC, const GLfixed *coords) \
x(void, glTexCoord2xOES, PFNGLTEXCOORD2XOESPROC, GLfixed s, GLfixed t) \
x(void, glTexCoord2xvOES, PFNGLTEXCOORD2XVOESPROC, const GLfixed *coords) \
x(void, glTexCoord3xOES, PFNGLTEXCOORD3XOESPROC, GLfixed s, GLfixed t, GLfixed r) \
x(void, glTexCoord3xvOES, PFNGLTEXCOORD3XVOESPROC, const GLfixed *coords) \
x(void, glTexCoord4xOES, PFNGLTEXCOORD4XOESPROC, GLfixed s, GLfixed t, GLfixed r, GLfixed q) \
x(void, glTexCoord4xvOES, PFNGLTEXCOORD4XVOESPROC, const GLfixed *coords) \
x(void, glTexGenxOES, PFNGLTEXGENXOESPROC, GLenum coord, GLenum pname, GLfixed param) \
x(void, glTexGenxvOES, PFNGLTEXGENXVOESPROC, GLenum coord, GLenum pname, const GLfixed *params) \
x(void, glVertex2xOES, PFNGLVERTEX2XOESPROC, GLfixed x) \
x(void, glVertex2xvOES, PFNGLVERTEX2XVOESPROC, const GLfixed *coords) \
x(void, glVertex3xOES, PFNGLVERTEX3XOESPROC, GLfixed x, GLfixed y) \
x(void, glVertex3xvOES, PFNGLVERTEX3XVOESPROC, const GLfixed *coords) \
x(void, glVertex4xOES, PFNGLVERTEX4XOESPROC, GLfixed x, GLfixed y, GLfixed z) \
x(void, glVertex4xvOES, PFNGLVERTEX4XVOESPROC, const GLfixed *coords) \
x(GLbitfield, glQueryMatrixxOES, PFNGLQUERYMATRIXXOESPROC, GLfixed *mantissa, GLint *exponent) \
x(void, glClearDepthfOES, PFNGLCLEARDEPTHFOESPROC, GLclampf depth) \
x(void, glClipPlanefOES, PFNGLCLIPPLANEFOESPROC, GLenum plane, const GLfloat *equation) \
x(void, glDepthRangefOES, PFNGLDEPTHRANGEFOESPROC, GLclampf n, GLclampf f) \
x(void, glFrustumfOES, PFNGLFRUSTUMFOESPROC, GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) \
x(void, glGetClipPlanefOES, PFNGLGETCLIPPLANEFOESPROC, GLenum plane, GLfloat *equation) \
x(void, glOrthofOES, PFNGLORTHOFOESPROC, GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) \
x(void, glTbufferMask3DFX, PFNGLTBUFFERMASK3DFXPROC, GLuint mask) \
x(void, glDebugMessageEnableAMD, PFNGLDEBUGMESSAGEENABLEAMDPROC, GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled) \
x(void, glDebugMessageInsertAMD, PFNGLDEBUGMESSAGEINSERTAMDPROC, GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf) \
x(void, glDebugMessageCallbackAMD, PFNGLDEBUGMESSAGECALLBACKAMDPROC, GLDEBUGPROCAMD callback, void *userParam) \
x(GLuint, glGetDebugMessageLogAMD, PFNGLGETDEBUGMESSAGELOGAMDPROC, GLuint count, GLsizei bufSize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message) \
x(void, glBlendFuncIndexedAMD, PFNGLBLENDFUNCINDEXEDAMDPROC, GLuint buf, GLenum src, GLenum dst) \
x(void, glBlendFuncSeparateIndexedAMD, PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) \
x(void, glBlendEquationIndexedAMD, PFNGLBLENDEQUATIONINDEXEDAMDPROC, GLuint buf, GLenum mode) \
x(void, glBlendEquationSeparateIndexedAMD, PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC, GLuint buf, GLenum modeRGB, GLenum modeAlpha) \
x(void, glRenderbufferStorageMultisampleAdvancedAMD, PFNGLRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC, GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glNamedRenderbufferStorageMultisampleAdvancedAMD, PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEADVANCEDAMDPROC, GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glFramebufferSamplePositionsfvAMD, PFNGLFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC, GLenum target, GLuint numsamples, GLuint pixelindex, const GLfloat *values) \
x(void, glNamedFramebufferSamplePositionsfvAMD, PFNGLNAMEDFRAMEBUFFERSAMPLEPOSITIONSFVAMDPROC, GLuint framebuffer, GLuint numsamples, GLuint pixelindex, const GLfloat *values) \
x(void, glGetFramebufferParameterfvAMD, PFNGLGETFRAMEBUFFERPARAMETERFVAMDPROC, GLenum target, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat *values) \
x(void, glGetNamedFramebufferParameterfvAMD, PFNGLGETNAMEDFRAMEBUFFERPARAMETERFVAMDPROC, GLuint framebuffer, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat *values) \
x(void, glUniform1i64NV, PFNGLUNIFORM1I64NVPROC, GLint location, GLint64EXT x) \
x(void, glUniform2i64NV, PFNGLUNIFORM2I64NVPROC, GLint location, GLint64EXT x, GLint64EXT y) \
x(void, glUniform3i64NV, PFNGLUNIFORM3I64NVPROC, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) \
x(void, glUniform4i64NV, PFNGLUNIFORM4I64NVPROC, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) \
x(void, glUniform1i64vNV, PFNGLUNIFORM1I64VNVPROC, GLint location, GLsizei count, const GLint64EXT *value) \
x(void, glUniform2i64vNV, PFNGLUNIFORM2I64VNVPROC, GLint location, GLsizei count, const GLint64EXT *value) \
x(void, glUniform3i64vNV, PFNGLUNIFORM3I64VNVPROC, GLint location, GLsizei count, const GLint64EXT *value) \
x(void, glUniform4i64vNV, PFNGLUNIFORM4I64VNVPROC, GLint location, GLsizei count, const GLint64EXT *value) \
x(void, glUniform1ui64NV, PFNGLUNIFORM1UI64NVPROC, GLint location, GLuint64EXT x) \
x(void, glUniform2ui64NV, PFNGLUNIFORM2UI64NVPROC, GLint location, GLuint64EXT x, GLuint64EXT y) \
x(void, glUniform3ui64NV, PFNGLUNIFORM3UI64NVPROC, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) \
x(void, glUniform4ui64NV, PFNGLUNIFORM4UI64NVPROC, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) \
x(void, glUniform1ui64vNV, PFNGLUNIFORM1UI64VNVPROC, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glUniform2ui64vNV, PFNGLUNIFORM2UI64VNVPROC, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glUniform3ui64vNV, PFNGLUNIFORM3UI64VNVPROC, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glUniform4ui64vNV, PFNGLUNIFORM4UI64VNVPROC, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glGetUniformi64vNV, PFNGLGETUNIFORMI64VNVPROC, GLuint program, GLint location, GLint64EXT *params) \
x(void, glGetUniformui64vNV, PFNGLGETUNIFORMUI64VNVPROC, GLuint program, GLint location, GLuint64EXT *params) \
x(void, glProgramUniform1i64NV, PFNGLPROGRAMUNIFORM1I64NVPROC, GLuint program, GLint location, GLint64EXT x) \
x(void, glProgramUniform2i64NV, PFNGLPROGRAMUNIFORM2I64NVPROC, GLuint program, GLint location, GLint64EXT x, GLint64EXT y) \
x(void, glProgramUniform3i64NV, PFNGLPROGRAMUNIFORM3I64NVPROC, GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) \
x(void, glProgramUniform4i64NV, PFNGLPROGRAMUNIFORM4I64NVPROC, GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) \
x(void, glProgramUniform1i64vNV, PFNGLPROGRAMUNIFORM1I64VNVPROC, GLuint program, GLint location, GLsizei count, const GLint64EXT *value) \
x(void, glProgramUniform2i64vNV, PFNGLPROGRAMUNIFORM2I64VNVPROC, GLuint program, GLint location, GLsizei count, const GLint64EXT *value) \
x(void, glProgramUniform3i64vNV, PFNGLPROGRAMUNIFORM3I64VNVPROC, GLuint program, GLint location, GLsizei count, const GLint64EXT *value) \
x(void, glProgramUniform4i64vNV, PFNGLPROGRAMUNIFORM4I64VNVPROC, GLuint program, GLint location, GLsizei count, const GLint64EXT *value) \
x(void, glProgramUniform1ui64NV, PFNGLPROGRAMUNIFORM1UI64NVPROC, GLuint program, GLint location, GLuint64EXT x) \
x(void, glProgramUniform2ui64NV, PFNGLPROGRAMUNIFORM2UI64NVPROC, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y) \
x(void, glProgramUniform3ui64NV, PFNGLPROGRAMUNIFORM3UI64NVPROC, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) \
x(void, glProgramUniform4ui64NV, PFNGLPROGRAMUNIFORM4UI64NVPROC, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) \
x(void, glProgramUniform1ui64vNV, PFNGLPROGRAMUNIFORM1UI64VNVPROC, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glProgramUniform2ui64vNV, PFNGLPROGRAMUNIFORM2UI64VNVPROC, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glProgramUniform3ui64vNV, PFNGLPROGRAMUNIFORM3UI64VNVPROC, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glProgramUniform4ui64vNV, PFNGLPROGRAMUNIFORM4UI64VNVPROC, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glVertexAttribParameteriAMD, PFNGLVERTEXATTRIBPARAMETERIAMDPROC, GLuint index, GLenum pname, GLint param) \
x(void, glMultiDrawArraysIndirectAMD, PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC, GLenum mode, const void *indirect, GLsizei primcount, GLsizei stride) \
x(void, glMultiDrawElementsIndirectAMD, PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC, GLenum mode, GLenum type, const void *indirect, GLsizei primcount, GLsizei stride) \
x(void, glGenNamesAMD, PFNGLGENNAMESAMDPROC, GLenum identifier, GLuint num, GLuint *names) \
x(void, glDeleteNamesAMD, PFNGLDELETENAMESAMDPROC, GLenum identifier, GLuint num, const GLuint *names) \
x(GLboolean, glIsNameAMD, PFNGLISNAMEAMDPROC, GLenum identifier, GLuint name) \
x(void, glQueryObjectParameteruiAMD, PFNGLQUERYOBJECTPARAMETERUIAMDPROC, GLenum target, GLuint id, GLenum pname, GLuint param) \
x(void, glGetPerfMonitorGroupsAMD, PFNGLGETPERFMONITORGROUPSAMDPROC, GLint *numGroups, GLsizei groupsSize, GLuint *groups) \
x(void, glGetPerfMonitorCountersAMD, PFNGLGETPERFMONITORCOUNTERSAMDPROC, GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters) \
x(void, glGetPerfMonitorGroupStringAMD, PFNGLGETPERFMONITORGROUPSTRINGAMDPROC, GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString) \
x(void, glGetPerfMonitorCounterStringAMD, PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC, GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString) \
x(void, glGetPerfMonitorCounterInfoAMD, PFNGLGETPERFMONITORCOUNTERINFOAMDPROC, GLuint group, GLuint counter, GLenum pname, void *data) \
x(void, glGenPerfMonitorsAMD, PFNGLGENPERFMONITORSAMDPROC, GLsizei n, GLuint *monitors) \
x(void, glDeletePerfMonitorsAMD, PFNGLDELETEPERFMONITORSAMDPROC, GLsizei n, GLuint *monitors) \
x(void, glSelectPerfMonitorCountersAMD, PFNGLSELECTPERFMONITORCOUNTERSAMDPROC, GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList) \
x(void, glBeginPerfMonitorAMD, PFNGLBEGINPERFMONITORAMDPROC, GLuint monitor) \
x(void, glEndPerfMonitorAMD, PFNGLENDPERFMONITORAMDPROC, GLuint monitor) \
x(void, glGetPerfMonitorCounterDataAMD, PFNGLGETPERFMONITORCOUNTERDATAAMDPROC, GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten) \
x(void, glSetMultisamplefvAMD, PFNGLSETMULTISAMPLEFVAMDPROC, GLenum pname, GLuint index, const GLfloat *val) \
x(void, glTexStorageSparseAMD, PFNGLTEXSTORAGESPARSEAMDPROC, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) \
x(void, glTextureStorageSparseAMD, PFNGLTEXTURESTORAGESPARSEAMDPROC, GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) \
x(void, glStencilOpValueAMD, PFNGLSTENCILOPVALUEAMDPROC, GLenum face, GLuint value) \
x(void, glTessellationFactorAMD, PFNGLTESSELLATIONFACTORAMDPROC, GLfloat factor) \
x(void, glTessellationModeAMD, PFNGLTESSELLATIONMODEAMDPROC, GLenum mode) \
x(void, glElementPointerAPPLE, PFNGLELEMENTPOINTERAPPLEPROC, GLenum type, const void *pointer) \
x(void, glDrawElementArrayAPPLE, PFNGLDRAWELEMENTARRAYAPPLEPROC, GLenum mode, GLint first, GLsizei count) \
x(void, glDrawRangeElementArrayAPPLE, PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count) \
x(void, glMultiDrawElementArrayAPPLE, PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount) \
x(void, glMultiDrawRangeElementArrayAPPLE, PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount) \
x(void, glGenFencesAPPLE, PFNGLGENFENCESAPPLEPROC, GLsizei n, GLuint *fences) \
x(void, glDeleteFencesAPPLE, PFNGLDELETEFENCESAPPLEPROC, GLsizei n, const GLuint *fences) \
x(void, glSetFenceAPPLE, PFNGLSETFENCEAPPLEPROC, GLuint fence) \
x(GLboolean, glIsFenceAPPLE, PFNGLISFENCEAPPLEPROC, GLuint fence) \
x(GLboolean, glTestFenceAPPLE, PFNGLTESTFENCEAPPLEPROC, GLuint fence) \
x(void, glFinishFenceAPPLE, PFNGLFINISHFENCEAPPLEPROC, GLuint fence) \
x(GLboolean, glTestObjectAPPLE, PFNGLTESTOBJECTAPPLEPROC, GLenum object, GLuint name) \
x(void, glFinishObjectAPPLE, PFNGLFINISHOBJECTAPPLEPROC, GLenum object, GLint name) \
x(void, glBufferParameteriAPPLE, PFNGLBUFFERPARAMETERIAPPLEPROC, GLenum target, GLenum pname, GLint param) \
x(void, glFlushMappedBufferRangeAPPLE, PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC, GLenum target, GLintptr offset, GLsizeiptr size) \
x(GLenum, glObjectPurgeableAPPLE, PFNGLOBJECTPURGEABLEAPPLEPROC, GLenum objectType, GLuint name, GLenum option) \
x(GLenum, glObjectUnpurgeableAPPLE, PFNGLOBJECTUNPURGEABLEAPPLEPROC, GLenum objectType, GLuint name, GLenum option) \
x(void, glGetObjectParameterivAPPLE, PFNGLGETOBJECTPARAMETERIVAPPLEPROC, GLenum objectType, GLuint name, GLenum pname, GLint *params) \
x(void, glTextureRangeAPPLE, PFNGLTEXTURERANGEAPPLEPROC, GLenum target, GLsizei length, const void *pointer) \
x(void, glGetTexParameterPointervAPPLE, PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC, GLenum target, GLenum pname, void **params) \
x(void, glBindVertexArrayAPPLE, PFNGLBINDVERTEXARRAYAPPLEPROC, GLuint array) \
x(void, glDeleteVertexArraysAPPLE, PFNGLDELETEVERTEXARRAYSAPPLEPROC, GLsizei n, const GLuint *arrays) \
x(void, glGenVertexArraysAPPLE, PFNGLGENVERTEXARRAYSAPPLEPROC, GLsizei n, GLuint *arrays) \
x(GLboolean, glIsVertexArrayAPPLE, PFNGLISVERTEXARRAYAPPLEPROC, GLuint array) \
x(void, glVertexArrayRangeAPPLE, PFNGLVERTEXARRAYRANGEAPPLEPROC, GLsizei length, void *pointer) \
x(void, glFlushVertexArrayRangeAPPLE, PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC, GLsizei length, void *pointer) \
x(void, glVertexArrayParameteriAPPLE, PFNGLVERTEXARRAYPARAMETERIAPPLEPROC, GLenum pname, GLint param) \
x(void, glEnableVertexAttribAPPLE, PFNGLENABLEVERTEXATTRIBAPPLEPROC, GLuint index, GLenum pname) \
x(void, glDisableVertexAttribAPPLE, PFNGLDISABLEVERTEXATTRIBAPPLEPROC, GLuint index, GLenum pname) \
x(GLboolean, glIsVertexAttribEnabledAPPLE, PFNGLISVERTEXATTRIBENABLEDAPPLEPROC, GLuint index, GLenum pname) \
x(void, glMapVertexAttrib1dAPPLE, PFNGLMAPVERTEXATTRIB1DAPPLEPROC, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points) \
x(void, glMapVertexAttrib1fAPPLE, PFNGLMAPVERTEXATTRIB1FAPPLEPROC, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points) \
x(void, glMapVertexAttrib2dAPPLE, PFNGLMAPVERTEXATTRIB2DAPPLEPROC, GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points) \
x(void, glMapVertexAttrib2fAPPLE, PFNGLMAPVERTEXATTRIB2FAPPLEPROC, GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points) \
x(void, glDrawBuffersATI, PFNGLDRAWBUFFERSATIPROC, GLsizei n, const GLenum *bufs) \
x(void, glElementPointerATI, PFNGLELEMENTPOINTERATIPROC, GLenum type, const void *pointer) \
x(void, glDrawElementArrayATI, PFNGLDRAWELEMENTARRAYATIPROC, GLenum mode, GLsizei count) \
x(void, glDrawRangeElementArrayATI, PFNGLDRAWRANGEELEMENTARRAYATIPROC, GLenum mode, GLuint start, GLuint end, GLsizei count) \
x(void, glTexBumpParameterivATI, PFNGLTEXBUMPPARAMETERIVATIPROC, GLenum pname, const GLint *param) \
x(void, glTexBumpParameterfvATI, PFNGLTEXBUMPPARAMETERFVATIPROC, GLenum pname, const GLfloat *param) \
x(void, glGetTexBumpParameterivATI, PFNGLGETTEXBUMPPARAMETERIVATIPROC, GLenum pname, GLint *param) \
x(void, glGetTexBumpParameterfvATI, PFNGLGETTEXBUMPPARAMETERFVATIPROC, GLenum pname, GLfloat *param) \
x(GLuint, glGenFragmentShadersATI, PFNGLGENFRAGMENTSHADERSATIPROC, GLuint range) \
x(void, glBindFragmentShaderATI, PFNGLBINDFRAGMENTSHADERATIPROC, GLuint id) \
x(void, glDeleteFragmentShaderATI, PFNGLDELETEFRAGMENTSHADERATIPROC, GLuint id) \
x(void, glBeginFragmentShaderATI, PFNGLBEGINFRAGMENTSHADERATIPROC, void) \
x(void, glEndFragmentShaderATI, PFNGLENDFRAGMENTSHADERATIPROC, void) \
x(void, glPassTexCoordATI, PFNGLPASSTEXCOORDATIPROC, GLuint dst, GLuint coord, GLenum swizzle) \
x(void, glSampleMapATI, PFNGLSAMPLEMAPATIPROC, GLuint dst, GLuint interp, GLenum swizzle) \
x(void, glColorFragmentOp1ATI, PFNGLCOLORFRAGMENTOP1ATIPROC, GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) \
x(void, glColorFragmentOp2ATI, PFNGLCOLORFRAGMENTOP2ATIPROC, GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) \
x(void, glColorFragmentOp3ATI, PFNGLCOLORFRAGMENTOP3ATIPROC, GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) \
x(void, glAlphaFragmentOp1ATI, PFNGLALPHAFRAGMENTOP1ATIPROC, GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) \
x(void, glAlphaFragmentOp2ATI, PFNGLALPHAFRAGMENTOP2ATIPROC, GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) \
x(void, glAlphaFragmentOp3ATI, PFNGLALPHAFRAGMENTOP3ATIPROC, GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) \
x(void, glSetFragmentShaderConstantATI, PFNGLSETFRAGMENTSHADERCONSTANTATIPROC, GLuint dst, const GLfloat *value) \
x(void, glUnmapObjectBufferATI, PFNGLUNMAPOBJECTBUFFERATIPROC, GLuint buffer) \
x(void, glPNTrianglesiATI, PFNGLPNTRIANGLESIATIPROC, GLenum pname, GLint param) \
x(void, glPNTrianglesfATI, PFNGLPNTRIANGLESFATIPROC, GLenum pname, GLfloat param) \
x(void, glStencilOpSeparateATI, PFNGLSTENCILOPSEPARATEATIPROC, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) \
x(void, glStencilFuncSeparateATI, PFNGLSTENCILFUNCSEPARATEATIPROC, GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask) \
x(GLuint, glNewObjectBufferATI, PFNGLNEWOBJECTBUFFERATIPROC, GLsizei size, const void *pointer, GLenum usage) \
x(GLboolean, glIsObjectBufferATI, PFNGLISOBJECTBUFFERATIPROC, GLuint buffer) \
x(void, glUpdateObjectBufferATI, PFNGLUPDATEOBJECTBUFFERATIPROC, GLuint buffer, GLuint offset, GLsizei size, const void *pointer, GLenum preserve) \
x(void, glGetObjectBufferfvATI, PFNGLGETOBJECTBUFFERFVATIPROC, GLuint buffer, GLenum pname, GLfloat *params) \
x(void, glGetObjectBufferivATI, PFNGLGETOBJECTBUFFERIVATIPROC, GLuint buffer, GLenum pname, GLint *params) \
x(void, glFreeObjectBufferATI, PFNGLFREEOBJECTBUFFERATIPROC, GLuint buffer) \
x(void, glArrayObjectATI, PFNGLARRAYOBJECTATIPROC, GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) \
x(void, glGetArrayObjectfvATI, PFNGLGETARRAYOBJECTFVATIPROC, GLenum array, GLenum pname, GLfloat *params) \
x(void, glGetArrayObjectivATI, PFNGLGETARRAYOBJECTIVATIPROC, GLenum array, GLenum pname, GLint *params) \
x(void, glVariantArrayObjectATI, PFNGLVARIANTARRAYOBJECTATIPROC, GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) \
x(void, glGetVariantArrayObjectfvATI, PFNGLGETVARIANTARRAYOBJECTFVATIPROC, GLuint id, GLenum pname, GLfloat *params) \
x(void, glGetVariantArrayObjectivATI, PFNGLGETVARIANTARRAYOBJECTIVATIPROC, GLuint id, GLenum pname, GLint *params) \
x(void, glVertexAttribArrayObjectATI, PFNGLVERTEXATTRIBARRAYOBJECTATIPROC, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset) \
x(void, glGetVertexAttribArrayObjectfvATI, PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC, GLuint index, GLenum pname, GLfloat *params) \
x(void, glGetVertexAttribArrayObjectivATI, PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC, GLuint index, GLenum pname, GLint *params) \
x(void, glVertexStream1sATI, PFNGLVERTEXSTREAM1SATIPROC, GLenum stream, GLshort x) \
x(void, glVertexStream1svATI, PFNGLVERTEXSTREAM1SVATIPROC, GLenum stream, const GLshort *coords) \
x(void, glVertexStream1iATI, PFNGLVERTEXSTREAM1IATIPROC, GLenum stream, GLint x) \
x(void, glVertexStream1ivATI, PFNGLVERTEXSTREAM1IVATIPROC, GLenum stream, const GLint *coords) \
x(void, glVertexStream1fATI, PFNGLVERTEXSTREAM1FATIPROC, GLenum stream, GLfloat x) \
x(void, glVertexStream1fvATI, PFNGLVERTEXSTREAM1FVATIPROC, GLenum stream, const GLfloat *coords) \
x(void, glVertexStream1dATI, PFNGLVERTEXSTREAM1DATIPROC, GLenum stream, GLdouble x) \
x(void, glVertexStream1dvATI, PFNGLVERTEXSTREAM1DVATIPROC, GLenum stream, const GLdouble *coords) \
x(void, glVertexStream2sATI, PFNGLVERTEXSTREAM2SATIPROC, GLenum stream, GLshort x, GLshort y) \
x(void, glVertexStream2svATI, PFNGLVERTEXSTREAM2SVATIPROC, GLenum stream, const GLshort *coords) \
x(void, glVertexStream2iATI, PFNGLVERTEXSTREAM2IATIPROC, GLenum stream, GLint x, GLint y) \
x(void, glVertexStream2ivATI, PFNGLVERTEXSTREAM2IVATIPROC, GLenum stream, const GLint *coords) \
x(void, glVertexStream2fATI, PFNGLVERTEXSTREAM2FATIPROC, GLenum stream, GLfloat x, GLfloat y) \
x(void, glVertexStream2fvATI, PFNGLVERTEXSTREAM2FVATIPROC, GLenum stream, const GLfloat *coords) \
x(void, glVertexStream2dATI, PFNGLVERTEXSTREAM2DATIPROC, GLenum stream, GLdouble x, GLdouble y) \
x(void, glVertexStream2dvATI, PFNGLVERTEXSTREAM2DVATIPROC, GLenum stream, const GLdouble *coords) \
x(void, glVertexStream3sATI, PFNGLVERTEXSTREAM3SATIPROC, GLenum stream, GLshort x, GLshort y, GLshort z) \
x(void, glVertexStream3svATI, PFNGLVERTEXSTREAM3SVATIPROC, GLenum stream, const GLshort *coords) \
x(void, glVertexStream3iATI, PFNGLVERTEXSTREAM3IATIPROC, GLenum stream, GLint x, GLint y, GLint z) \
x(void, glVertexStream3ivATI, PFNGLVERTEXSTREAM3IVATIPROC, GLenum stream, const GLint *coords) \
x(void, glVertexStream3fATI, PFNGLVERTEXSTREAM3FATIPROC, GLenum stream, GLfloat x, GLfloat y, GLfloat z) \
x(void, glVertexStream3fvATI, PFNGLVERTEXSTREAM3FVATIPROC, GLenum stream, const GLfloat *coords) \
x(void, glVertexStream3dATI, PFNGLVERTEXSTREAM3DATIPROC, GLenum stream, GLdouble x, GLdouble y, GLdouble z) \
x(void, glVertexStream3dvATI, PFNGLVERTEXSTREAM3DVATIPROC, GLenum stream, const GLdouble *coords) \
x(void, glVertexStream4sATI, PFNGLVERTEXSTREAM4SATIPROC, GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w) \
x(void, glVertexStream4svATI, PFNGLVERTEXSTREAM4SVATIPROC, GLenum stream, const GLshort *coords) \
x(void, glVertexStream4iATI, PFNGLVERTEXSTREAM4IATIPROC, GLenum stream, GLint x, GLint y, GLint z, GLint w) \
x(void, glVertexStream4ivATI, PFNGLVERTEXSTREAM4IVATIPROC, GLenum stream, const GLint *coords) \
x(void, glVertexStream4fATI, PFNGLVERTEXSTREAM4FATIPROC, GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glVertexStream4fvATI, PFNGLVERTEXSTREAM4FVATIPROC, GLenum stream, const GLfloat *coords) \
x(void, glVertexStream4dATI, PFNGLVERTEXSTREAM4DATIPROC, GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glVertexStream4dvATI, PFNGLVERTEXSTREAM4DVATIPROC, GLenum stream, const GLdouble *coords) \
x(void, glNormalStream3bATI, PFNGLNORMALSTREAM3BATIPROC, GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz) \
x(void, glNormalStream3bvATI, PFNGLNORMALSTREAM3BVATIPROC, GLenum stream, const GLbyte *coords) \
x(void, glNormalStream3sATI, PFNGLNORMALSTREAM3SATIPROC, GLenum stream, GLshort nx, GLshort ny, GLshort nz) \
x(void, glNormalStream3svATI, PFNGLNORMALSTREAM3SVATIPROC, GLenum stream, const GLshort *coords) \
x(void, glNormalStream3iATI, PFNGLNORMALSTREAM3IATIPROC, GLenum stream, GLint nx, GLint ny, GLint nz) \
x(void, glNormalStream3ivATI, PFNGLNORMALSTREAM3IVATIPROC, GLenum stream, const GLint *coords) \
x(void, glNormalStream3fATI, PFNGLNORMALSTREAM3FATIPROC, GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz) \
x(void, glNormalStream3fvATI, PFNGLNORMALSTREAM3FVATIPROC, GLenum stream, const GLfloat *coords) \
x(void, glNormalStream3dATI, PFNGLNORMALSTREAM3DATIPROC, GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz) \
x(void, glNormalStream3dvATI, PFNGLNORMALSTREAM3DVATIPROC, GLenum stream, const GLdouble *coords) \
x(void, glClientActiveVertexStreamATI, PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC, GLenum stream) \
x(void, glVertexBlendEnviATI, PFNGLVERTEXBLENDENVIATIPROC, GLenum pname, GLint param) \
x(void, glVertexBlendEnvfATI, PFNGLVERTEXBLENDENVFATIPROC, GLenum pname, GLfloat param) \
x(void, glEGLImageTargetTexStorageEXT, PFNGLEGLIMAGETARGETTEXSTORAGEEXTPROC, GLenum target, GLeglImageOES image, const GLint* attrib_list) \
x(void, glEGLImageTargetTextureStorageEXT, PFNGLEGLIMAGETARGETTEXTURESTORAGEEXTPROC, GLuint texture, GLeglImageOES image, const GLint* attrib_list) \
x(void, glUniformBufferEXT, PFNGLUNIFORMBUFFEREXTPROC, GLuint program, GLint location, GLuint buffer) \
x(GLint, glGetUniformBufferSizeEXT, PFNGLGETUNIFORMBUFFERSIZEEXTPROC, GLuint program, GLint location) \
x(GLintptr, glGetUniformOffsetEXT, PFNGLGETUNIFORMOFFSETEXTPROC, GLuint program, GLint location) \
x(void, glBlendColorEXT, PFNGLBLENDCOLOREXTPROC, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) \
x(void, glBlendEquationSeparateEXT, PFNGLBLENDEQUATIONSEPARATEEXTPROC, GLenum modeRGB, GLenum modeAlpha) \
x(void, glBlendFuncSeparateEXT, PFNGLBLENDFUNCSEPARATEEXTPROC, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) \
x(void, glBlendEquationEXT, PFNGLBLENDEQUATIONEXTPROC, GLenum mode) \
x(void, glColorSubTableEXT, PFNGLCOLORSUBTABLEEXTPROC, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data) \
x(void, glCopyColorSubTableEXT, PFNGLCOPYCOLORSUBTABLEEXTPROC, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) \
x(void, glLockArraysEXT, PFNGLLOCKARRAYSEXTPROC, GLint first, GLsizei count) \
x(void, glUnlockArraysEXT, PFNGLUNLOCKARRAYSEXTPROC, void) \
x(void, glConvolutionFilter1DEXT, PFNGLCONVOLUTIONFILTER1DEXTPROC, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image) \
x(void, glConvolutionFilter2DEXT, PFNGLCONVOLUTIONFILTER2DEXTPROC, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image) \
x(void, glConvolutionParameterfEXT, PFNGLCONVOLUTIONPARAMETERFEXTPROC, GLenum target, GLenum pname, GLfloat params) \
x(void, glConvolutionParameterfvEXT, PFNGLCONVOLUTIONPARAMETERFVEXTPROC, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glConvolutionParameteriEXT, PFNGLCONVOLUTIONPARAMETERIEXTPROC, GLenum target, GLenum pname, GLint params) \
x(void, glConvolutionParameterivEXT, PFNGLCONVOLUTIONPARAMETERIVEXTPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glCopyConvolutionFilter1DEXT, PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) \
x(void, glCopyConvolutionFilter2DEXT, PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glGetConvolutionFilterEXT, PFNGLGETCONVOLUTIONFILTEREXTPROC, GLenum target, GLenum format, GLenum type, void *image) \
x(void, glGetConvolutionParameterfvEXT, PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetConvolutionParameterivEXT, PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetSeparableFilterEXT, PFNGLGETSEPARABLEFILTEREXTPROC, GLenum target, GLenum format, GLenum type, void *row, void *column, void *span) \
x(void, glSeparableFilter2DEXT, PFNGLSEPARABLEFILTER2DEXTPROC, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column) \
x(void, glTangent3bEXT, PFNGLTANGENT3BEXTPROC, GLbyte tx, GLbyte ty, GLbyte tz) \
x(void, glTangent3bvEXT, PFNGLTANGENT3BVEXTPROC, const GLbyte *v) \
x(void, glTangent3dEXT, PFNGLTANGENT3DEXTPROC, GLdouble tx, GLdouble ty, GLdouble tz) \
x(void, glTangent3dvEXT, PFNGLTANGENT3DVEXTPROC, const GLdouble *v) \
x(void, glTangent3fEXT, PFNGLTANGENT3FEXTPROC, GLfloat tx, GLfloat ty, GLfloat tz) \
x(void, glTangent3fvEXT, PFNGLTANGENT3FVEXTPROC, const GLfloat *v) \
x(void, glTangent3iEXT, PFNGLTANGENT3IEXTPROC, GLint tx, GLint ty, GLint tz) \
x(void, glTangent3ivEXT, PFNGLTANGENT3IVEXTPROC, const GLint *v) \
x(void, glTangent3sEXT, PFNGLTANGENT3SEXTPROC, GLshort tx, GLshort ty, GLshort tz) \
x(void, glTangent3svEXT, PFNGLTANGENT3SVEXTPROC, const GLshort *v) \
x(void, glBinormal3bEXT, PFNGLBINORMAL3BEXTPROC, GLbyte bx, GLbyte by, GLbyte bz) \
x(void, glBinormal3bvEXT, PFNGLBINORMAL3BVEXTPROC, const GLbyte *v) \
x(void, glBinormal3dEXT, PFNGLBINORMAL3DEXTPROC, GLdouble bx, GLdouble by, GLdouble bz) \
x(void, glBinormal3dvEXT, PFNGLBINORMAL3DVEXTPROC, const GLdouble *v) \
x(void, glBinormal3fEXT, PFNGLBINORMAL3FEXTPROC, GLfloat bx, GLfloat by, GLfloat bz) \
x(void, glBinormal3fvEXT, PFNGLBINORMAL3FVEXTPROC, const GLfloat *v) \
x(void, glBinormal3iEXT, PFNGLBINORMAL3IEXTPROC, GLint bx, GLint by, GLint bz) \
x(void, glBinormal3ivEXT, PFNGLBINORMAL3IVEXTPROC, const GLint *v) \
x(void, glBinormal3sEXT, PFNGLBINORMAL3SEXTPROC, GLshort bx, GLshort by, GLshort bz) \
x(void, glBinormal3svEXT, PFNGLBINORMAL3SVEXTPROC, const GLshort *v) \
x(void, glTangentPointerEXT, PFNGLTANGENTPOINTEREXTPROC, GLenum type, GLsizei stride, const void *pointer) \
x(void, glBinormalPointerEXT, PFNGLBINORMALPOINTEREXTPROC, GLenum type, GLsizei stride, const void *pointer) \
x(void, glCopyTexImage1DEXT, PFNGLCOPYTEXIMAGE1DEXTPROC, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) \
x(void, glCopyTexImage2DEXT, PFNGLCOPYTEXIMAGE2DEXTPROC, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) \
x(void, glCopyTexSubImage1DEXT, PFNGLCOPYTEXSUBIMAGE1DEXTPROC, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) \
x(void, glCopyTexSubImage2DEXT, PFNGLCOPYTEXSUBIMAGE2DEXTPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glCopyTexSubImage3DEXT, PFNGLCOPYTEXSUBIMAGE3DEXTPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glCullParameterdvEXT, PFNGLCULLPARAMETERDVEXTPROC, GLenum pname, GLdouble *params) \
x(void, glCullParameterfvEXT, PFNGLCULLPARAMETERFVEXTPROC, GLenum pname, GLfloat *params) \
x(void, glLabelObjectEXT, PFNGLLABELOBJECTEXTPROC, GLenum type, GLuint object, GLsizei length, const GLchar *label) \
x(void, glGetObjectLabelEXT, PFNGLGETOBJECTLABELEXTPROC, GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label) \
x(void, glInsertEventMarkerEXT, PFNGLINSERTEVENTMARKEREXTPROC, GLsizei length, const GLchar *marker) \
x(void, glPushGroupMarkerEXT, PFNGLPUSHGROUPMARKEREXTPROC, GLsizei length, const GLchar *marker) \
x(void, glPopGroupMarkerEXT, PFNGLPOPGROUPMARKEREXTPROC, void) \
x(void, glDepthBoundsEXT, PFNGLDEPTHBOUNDSEXTPROC, GLclampd zmin, GLclampd zmax) \
x(void, glMatrixLoadfEXT, PFNGLMATRIXLOADFEXTPROC, GLenum mode, const GLfloat *m) \
x(void, glMatrixLoaddEXT, PFNGLMATRIXLOADDEXTPROC, GLenum mode, const GLdouble *m) \
x(void, glMatrixMultfEXT, PFNGLMATRIXMULTFEXTPROC, GLenum mode, const GLfloat *m) \
x(void, glMatrixMultdEXT, PFNGLMATRIXMULTDEXTPROC, GLenum mode, const GLdouble *m) \
x(void, glMatrixLoadIdentityEXT, PFNGLMATRIXLOADIDENTITYEXTPROC, GLenum mode) \
x(void, glMatrixRotatefEXT, PFNGLMATRIXROTATEFEXTPROC, GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) \
x(void, glMatrixRotatedEXT, PFNGLMATRIXROTATEDEXTPROC, GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) \
x(void, glMatrixScalefEXT, PFNGLMATRIXSCALEFEXTPROC, GLenum mode, GLfloat x, GLfloat y, GLfloat z) \
x(void, glMatrixScaledEXT, PFNGLMATRIXSCALEDEXTPROC, GLenum mode, GLdouble x, GLdouble y, GLdouble z) \
x(void, glMatrixTranslatefEXT, PFNGLMATRIXTRANSLATEFEXTPROC, GLenum mode, GLfloat x, GLfloat y, GLfloat z) \
x(void, glMatrixTranslatedEXT, PFNGLMATRIXTRANSLATEDEXTPROC, GLenum mode, GLdouble x, GLdouble y, GLdouble z) \
x(void, glMatrixFrustumEXT, PFNGLMATRIXFRUSTUMEXTPROC, GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) \
x(void, glMatrixOrthoEXT, PFNGLMATRIXORTHOEXTPROC, GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) \
x(void, glMatrixPopEXT, PFNGLMATRIXPOPEXTPROC, GLenum mode) \
x(void, glMatrixPushEXT, PFNGLMATRIXPUSHEXTPROC, GLenum mode) \
x(void, glClientAttribDefaultEXT, PFNGLCLIENTATTRIBDEFAULTEXTPROC, GLbitfield mask) \
x(void, glPushClientAttribDefaultEXT, PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC, GLbitfield mask) \
x(void, glTextureParameterfEXT, PFNGLTEXTUREPARAMETERFEXTPROC, GLuint texture, GLenum target, GLenum pname, GLfloat param) \
x(void, glTextureParameterfvEXT, PFNGLTEXTUREPARAMETERFVEXTPROC, GLuint texture, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glTextureParameteriEXT, PFNGLTEXTUREPARAMETERIEXTPROC, GLuint texture, GLenum target, GLenum pname, GLint param) \
x(void, glTextureParameterivEXT, PFNGLTEXTUREPARAMETERIVEXTPROC, GLuint texture, GLenum target, GLenum pname, const GLint *params) \
x(void, glTextureImage1DEXT, PFNGLTEXTUREIMAGE1DEXTPROC, GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glTextureImage2DEXT, PFNGLTEXTUREIMAGE2DEXTPROC, GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glTextureSubImage1DEXT, PFNGLTEXTURESUBIMAGE1DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) \
x(void, glTextureSubImage2DEXT, PFNGLTEXTURESUBIMAGE2DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) \
x(void, glCopyTextureImage1DEXT, PFNGLCOPYTEXTUREIMAGE1DEXTPROC, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) \
x(void, glCopyTextureImage2DEXT, PFNGLCOPYTEXTUREIMAGE2DEXTPROC, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) \
x(void, glCopyTextureSubImage1DEXT, PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) \
x(void, glCopyTextureSubImage2DEXT, PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glGetTextureImageEXT, PFNGLGETTEXTUREIMAGEEXTPROC, GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels) \
x(void, glGetTextureParameterfvEXT, PFNGLGETTEXTUREPARAMETERFVEXTPROC, GLuint texture, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetTextureParameterivEXT, PFNGLGETTEXTUREPARAMETERIVEXTPROC, GLuint texture, GLenum target, GLenum pname, GLint *params) \
x(void, glGetTextureLevelParameterfvEXT, PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC, GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params) \
x(void, glGetTextureLevelParameterivEXT, PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC, GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params) \
x(void, glTextureImage3DEXT, PFNGLTEXTUREIMAGE3DEXTPROC, GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glTextureSubImage3DEXT, PFNGLTEXTURESUBIMAGE3DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) \
x(void, glCopyTextureSubImage3DEXT, PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glBindMultiTextureEXT, PFNGLBINDMULTITEXTUREEXTPROC, GLenum texunit, GLenum target, GLuint texture) \
x(void, glMultiTexCoordPointerEXT, PFNGLMULTITEXCOORDPOINTEREXTPROC, GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glMultiTexEnvfEXT, PFNGLMULTITEXENVFEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLfloat param) \
x(void, glMultiTexEnvfvEXT, PFNGLMULTITEXENVFVEXTPROC, GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glMultiTexEnviEXT, PFNGLMULTITEXENVIEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLint param) \
x(void, glMultiTexEnvivEXT, PFNGLMULTITEXENVIVEXTPROC, GLenum texunit, GLenum target, GLenum pname, const GLint *params) \
x(void, glMultiTexGendEXT, PFNGLMULTITEXGENDEXTPROC, GLenum texunit, GLenum coord, GLenum pname, GLdouble param) \
x(void, glMultiTexGendvEXT, PFNGLMULTITEXGENDVEXTPROC, GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params) \
x(void, glMultiTexGenfEXT, PFNGLMULTITEXGENFEXTPROC, GLenum texunit, GLenum coord, GLenum pname, GLfloat param) \
x(void, glMultiTexGenfvEXT, PFNGLMULTITEXGENFVEXTPROC, GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params) \
x(void, glMultiTexGeniEXT, PFNGLMULTITEXGENIEXTPROC, GLenum texunit, GLenum coord, GLenum pname, GLint param) \
x(void, glMultiTexGenivEXT, PFNGLMULTITEXGENIVEXTPROC, GLenum texunit, GLenum coord, GLenum pname, const GLint *params) \
x(void, glGetMultiTexEnvfvEXT, PFNGLGETMULTITEXENVFVEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetMultiTexEnvivEXT, PFNGLGETMULTITEXENVIVEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLint *params) \
x(void, glGetMultiTexGendvEXT, PFNGLGETMULTITEXGENDVEXTPROC, GLenum texunit, GLenum coord, GLenum pname, GLdouble *params) \
x(void, glGetMultiTexGenfvEXT, PFNGLGETMULTITEXGENFVEXTPROC, GLenum texunit, GLenum coord, GLenum pname, GLfloat *params) \
x(void, glGetMultiTexGenivEXT, PFNGLGETMULTITEXGENIVEXTPROC, GLenum texunit, GLenum coord, GLenum pname, GLint *params) \
x(void, glMultiTexParameteriEXT, PFNGLMULTITEXPARAMETERIEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLint param) \
x(void, glMultiTexParameterivEXT, PFNGLMULTITEXPARAMETERIVEXTPROC, GLenum texunit, GLenum target, GLenum pname, const GLint *params) \
x(void, glMultiTexParameterfEXT, PFNGLMULTITEXPARAMETERFEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLfloat param) \
x(void, glMultiTexParameterfvEXT, PFNGLMULTITEXPARAMETERFVEXTPROC, GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glMultiTexImage1DEXT, PFNGLMULTITEXIMAGE1DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glMultiTexImage2DEXT, PFNGLMULTITEXIMAGE2DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glMultiTexSubImage1DEXT, PFNGLMULTITEXSUBIMAGE1DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) \
x(void, glMultiTexSubImage2DEXT, PFNGLMULTITEXSUBIMAGE2DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) \
x(void, glCopyMultiTexImage1DEXT, PFNGLCOPYMULTITEXIMAGE1DEXTPROC, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) \
x(void, glCopyMultiTexImage2DEXT, PFNGLCOPYMULTITEXIMAGE2DEXTPROC, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) \
x(void, glCopyMultiTexSubImage1DEXT, PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) \
x(void, glCopyMultiTexSubImage2DEXT, PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glGetMultiTexImageEXT, PFNGLGETMULTITEXIMAGEEXTPROC, GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels) \
x(void, glGetMultiTexParameterfvEXT, PFNGLGETMULTITEXPARAMETERFVEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetMultiTexParameterivEXT, PFNGLGETMULTITEXPARAMETERIVEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLint *params) \
x(void, glGetMultiTexLevelParameterfvEXT, PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC, GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params) \
x(void, glGetMultiTexLevelParameterivEXT, PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC, GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params) \
x(void, glMultiTexImage3DEXT, PFNGLMULTITEXIMAGE3DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glMultiTexSubImage3DEXT, PFNGLMULTITEXSUBIMAGE3DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) \
x(void, glCopyMultiTexSubImage3DEXT, PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glEnableClientStateIndexedEXT, PFNGLENABLECLIENTSTATEINDEXEDEXTPROC, GLenum array, GLuint index) \
x(void, glDisableClientStateIndexedEXT, PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC, GLenum array, GLuint index) \
x(void, glGetFloatIndexedvEXT, PFNGLGETFLOATINDEXEDVEXTPROC, GLenum target, GLuint index, GLfloat *data) \
x(void, glGetDoubleIndexedvEXT, PFNGLGETDOUBLEINDEXEDVEXTPROC, GLenum target, GLuint index, GLdouble *data) \
x(void, glGetPointerIndexedvEXT, PFNGLGETPOINTERINDEXEDVEXTPROC, GLenum target, GLuint index, void **data) \
x(void, glEnableIndexedEXT, PFNGLENABLEINDEXEDEXTPROC, GLenum target, GLuint index) \
x(void, glDisableIndexedEXT, PFNGLDISABLEINDEXEDEXTPROC, GLenum target, GLuint index) \
x(GLboolean, glIsEnabledIndexedEXT, PFNGLISENABLEDINDEXEDEXTPROC, GLenum target, GLuint index) \
x(void, glGetIntegerIndexedvEXT, PFNGLGETINTEGERINDEXEDVEXTPROC, GLenum target, GLuint index, GLint *data) \
x(void, glGetBooleanIndexedvEXT, PFNGLGETBOOLEANINDEXEDVEXTPROC, GLenum target, GLuint index, GLboolean *data) \
x(void, glCompressedTextureImage3DEXT, PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits) \
x(void, glCompressedTextureImage2DEXT, PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits) \
x(void, glCompressedTextureImage1DEXT, PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC, GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits) \
x(void, glCompressedTextureSubImage3DEXT, PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits) \
x(void, glCompressedTextureSubImage2DEXT, PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits) \
x(void, glCompressedTextureSubImage1DEXT, PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC, GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits) \
x(void, glGetCompressedTextureImageEXT, PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC, GLuint texture, GLenum target, GLint lod, void *img) \
x(void, glCompressedMultiTexImage3DEXT, PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits) \
x(void, glCompressedMultiTexImage2DEXT, PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits) \
x(void, glCompressedMultiTexImage1DEXT, PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC, GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits) \
x(void, glCompressedMultiTexSubImage3DEXT, PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits) \
x(void, glCompressedMultiTexSubImage2DEXT, PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits) \
x(void, glCompressedMultiTexSubImage1DEXT, PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC, GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits) \
x(void, glGetCompressedMultiTexImageEXT, PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC, GLenum texunit, GLenum target, GLint lod, void *img) \
x(void, glMatrixLoadTransposefEXT, PFNGLMATRIXLOADTRANSPOSEFEXTPROC, GLenum mode, const GLfloat *m) \
x(void, glMatrixLoadTransposedEXT, PFNGLMATRIXLOADTRANSPOSEDEXTPROC, GLenum mode, const GLdouble *m) \
x(void, glMatrixMultTransposefEXT, PFNGLMATRIXMULTTRANSPOSEFEXTPROC, GLenum mode, const GLfloat *m) \
x(void, glMatrixMultTransposedEXT, PFNGLMATRIXMULTTRANSPOSEDEXTPROC, GLenum mode, const GLdouble *m) \
x(void, glNamedBufferDataEXT, PFNGLNAMEDBUFFERDATAEXTPROC, GLuint buffer, GLsizeiptr size, const void *data, GLenum usage) \
x(void, glNamedBufferSubDataEXT, PFNGLNAMEDBUFFERSUBDATAEXTPROC, GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) \
x(GLboolean, glUnmapNamedBufferEXT, PFNGLUNMAPNAMEDBUFFEREXTPROC, GLuint buffer) \
x(void, glGetNamedBufferParameterivEXT, PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC, GLuint buffer, GLenum pname, GLint *params) \
x(void, glGetNamedBufferPointervEXT, PFNGLGETNAMEDBUFFERPOINTERVEXTPROC, GLuint buffer, GLenum pname, void **params) \
x(void, glGetNamedBufferSubDataEXT, PFNGLGETNAMEDBUFFERSUBDATAEXTPROC, GLuint buffer, GLintptr offset, GLsizeiptr size, void *data) \
x(void, glProgramUniform1fEXT, PFNGLPROGRAMUNIFORM1FEXTPROC, GLuint program, GLint location, GLfloat v0) \
x(void, glProgramUniform2fEXT, PFNGLPROGRAMUNIFORM2FEXTPROC, GLuint program, GLint location, GLfloat v0, GLfloat v1) \
x(void, glProgramUniform3fEXT, PFNGLPROGRAMUNIFORM3FEXTPROC, GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) \
x(void, glProgramUniform4fEXT, PFNGLPROGRAMUNIFORM4FEXTPROC, GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) \
x(void, glProgramUniform1iEXT, PFNGLPROGRAMUNIFORM1IEXTPROC, GLuint program, GLint location, GLint v0) \
x(void, glProgramUniform2iEXT, PFNGLPROGRAMUNIFORM2IEXTPROC, GLuint program, GLint location, GLint v0, GLint v1) \
x(void, glProgramUniform3iEXT, PFNGLPROGRAMUNIFORM3IEXTPROC, GLuint program, GLint location, GLint v0, GLint v1, GLint v2) \
x(void, glProgramUniform4iEXT, PFNGLPROGRAMUNIFORM4IEXTPROC, GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) \
x(void, glProgramUniform1fvEXT, PFNGLPROGRAMUNIFORM1FVEXTPROC, GLuint program, GLint location, GLsizei count, const GLfloat *value) \
x(void, glProgramUniform2fvEXT, PFNGLPROGRAMUNIFORM2FVEXTPROC, GLuint program, GLint location, GLsizei count, const GLfloat *value) \
x(void, glProgramUniform3fvEXT, PFNGLPROGRAMUNIFORM3FVEXTPROC, GLuint program, GLint location, GLsizei count, const GLfloat *value) \
x(void, glProgramUniform4fvEXT, PFNGLPROGRAMUNIFORM4FVEXTPROC, GLuint program, GLint location, GLsizei count, const GLfloat *value) \
x(void, glProgramUniform1ivEXT, PFNGLPROGRAMUNIFORM1IVEXTPROC, GLuint program, GLint location, GLsizei count, const GLint *value) \
x(void, glProgramUniform2ivEXT, PFNGLPROGRAMUNIFORM2IVEXTPROC, GLuint program, GLint location, GLsizei count, const GLint *value) \
x(void, glProgramUniform3ivEXT, PFNGLPROGRAMUNIFORM3IVEXTPROC, GLuint program, GLint location, GLsizei count, const GLint *value) \
x(void, glProgramUniform4ivEXT, PFNGLPROGRAMUNIFORM4IVEXTPROC, GLuint program, GLint location, GLsizei count, const GLint *value) \
x(void, glProgramUniformMatrix2fvEXT, PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix3fvEXT, PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix4fvEXT, PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix2x3fvEXT, PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix3x2fvEXT, PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix2x4fvEXT, PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix4x2fvEXT, PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix3x4fvEXT, PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glProgramUniformMatrix4x3fvEXT, PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) \
x(void, glTextureBufferEXT, PFNGLTEXTUREBUFFEREXTPROC, GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) \
x(void, glMultiTexBufferEXT, PFNGLMULTITEXBUFFEREXTPROC, GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) \
x(void, glTextureParameterIivEXT, PFNGLTEXTUREPARAMETERIIVEXTPROC, GLuint texture, GLenum target, GLenum pname, const GLint *params) \
x(void, glTextureParameterIuivEXT, PFNGLTEXTUREPARAMETERIUIVEXTPROC, GLuint texture, GLenum target, GLenum pname, const GLuint *params) \
x(void, glGetTextureParameterIivEXT, PFNGLGETTEXTUREPARAMETERIIVEXTPROC, GLuint texture, GLenum target, GLenum pname, GLint *params) \
x(void, glGetTextureParameterIuivEXT, PFNGLGETTEXTUREPARAMETERIUIVEXTPROC, GLuint texture, GLenum target, GLenum pname, GLuint *params) \
x(void, glMultiTexParameterIivEXT, PFNGLMULTITEXPARAMETERIIVEXTPROC, GLenum texunit, GLenum target, GLenum pname, const GLint *params) \
x(void, glMultiTexParameterIuivEXT, PFNGLMULTITEXPARAMETERIUIVEXTPROC, GLenum texunit, GLenum target, GLenum pname, const GLuint *params) \
x(void, glGetMultiTexParameterIivEXT, PFNGLGETMULTITEXPARAMETERIIVEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLint *params) \
x(void, glGetMultiTexParameterIuivEXT, PFNGLGETMULTITEXPARAMETERIUIVEXTPROC, GLenum texunit, GLenum target, GLenum pname, GLuint *params) \
x(void, glProgramUniform1uiEXT, PFNGLPROGRAMUNIFORM1UIEXTPROC, GLuint program, GLint location, GLuint v0) \
x(void, glProgramUniform2uiEXT, PFNGLPROGRAMUNIFORM2UIEXTPROC, GLuint program, GLint location, GLuint v0, GLuint v1) \
x(void, glProgramUniform3uiEXT, PFNGLPROGRAMUNIFORM3UIEXTPROC, GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) \
x(void, glProgramUniform4uiEXT, PFNGLPROGRAMUNIFORM4UIEXTPROC, GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) \
x(void, glProgramUniform1uivEXT, PFNGLPROGRAMUNIFORM1UIVEXTPROC, GLuint program, GLint location, GLsizei count, const GLuint *value) \
x(void, glProgramUniform2uivEXT, PFNGLPROGRAMUNIFORM2UIVEXTPROC, GLuint program, GLint location, GLsizei count, const GLuint *value) \
x(void, glProgramUniform3uivEXT, PFNGLPROGRAMUNIFORM3UIVEXTPROC, GLuint program, GLint location, GLsizei count, const GLuint *value) \
x(void, glProgramUniform4uivEXT, PFNGLPROGRAMUNIFORM4UIVEXTPROC, GLuint program, GLint location, GLsizei count, const GLuint *value) \
x(void, glNamedProgramLocalParameters4fvEXT, PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC, GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params) \
x(void, glNamedProgramLocalParameterI4iEXT, PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC, GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) \
x(void, glNamedProgramLocalParameterI4ivEXT, PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC, GLuint program, GLenum target, GLuint index, const GLint *params) \
x(void, glNamedProgramLocalParametersI4ivEXT, PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC, GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params) \
x(void, glNamedProgramLocalParameterI4uiEXT, PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC, GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) \
x(void, glNamedProgramLocalParameterI4uivEXT, PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC, GLuint program, GLenum target, GLuint index, const GLuint *params) \
x(void, glNamedProgramLocalParametersI4uivEXT, PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC, GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params) \
x(void, glGetNamedProgramLocalParameterIivEXT, PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC, GLuint program, GLenum target, GLuint index, GLint *params) \
x(void, glGetNamedProgramLocalParameterIuivEXT, PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC, GLuint program, GLenum target, GLuint index, GLuint *params) \
x(void, glEnableClientStateiEXT, PFNGLENABLECLIENTSTATEIEXTPROC, GLenum array, GLuint index) \
x(void, glDisableClientStateiEXT, PFNGLDISABLECLIENTSTATEIEXTPROC, GLenum array, GLuint index) \
x(void, glGetFloati_vEXT, PFNGLGETFLOATI_VEXTPROC, GLenum pname, GLuint index, GLfloat *params) \
x(void, glGetDoublei_vEXT, PFNGLGETDOUBLEI_VEXTPROC, GLenum pname, GLuint index, GLdouble *params) \
x(void, glGetPointeri_vEXT, PFNGLGETPOINTERI_VEXTPROC, GLenum pname, GLuint index, void **params) \
x(void, glNamedProgramStringEXT, PFNGLNAMEDPROGRAMSTRINGEXTPROC, GLuint program, GLenum target, GLenum format, GLsizei len, const void *string) \
x(void, glNamedProgramLocalParameter4dEXT, PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC, GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glNamedProgramLocalParameter4dvEXT, PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC, GLuint program, GLenum target, GLuint index, const GLdouble *params) \
x(void, glNamedProgramLocalParameter4fEXT, PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC, GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glNamedProgramLocalParameter4fvEXT, PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC, GLuint program, GLenum target, GLuint index, const GLfloat *params) \
x(void, glGetNamedProgramLocalParameterdvEXT, PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC, GLuint program, GLenum target, GLuint index, GLdouble *params) \
x(void, glGetNamedProgramLocalParameterfvEXT, PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC, GLuint program, GLenum target, GLuint index, GLfloat *params) \
x(void, glGetNamedProgramivEXT, PFNGLGETNAMEDPROGRAMIVEXTPROC, GLuint program, GLenum target, GLenum pname, GLint *params) \
x(void, glGetNamedProgramStringEXT, PFNGLGETNAMEDPROGRAMSTRINGEXTPROC, GLuint program, GLenum target, GLenum pname, void *string) \
x(void, glNamedRenderbufferStorageEXT, PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC, GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glGetNamedRenderbufferParameterivEXT, PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC, GLuint renderbuffer, GLenum pname, GLint *params) \
x(void, glNamedRenderbufferStorageMultisampleEXT, PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC, GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glNamedRenderbufferStorageMultisampleCoverageEXT, PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC, GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) \
x(GLenum, glCheckNamedFramebufferStatusEXT, PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC, GLuint framebuffer, GLenum target) \
x(void, glNamedFramebufferTexture1DEXT, PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC, GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) \
x(void, glNamedFramebufferTexture2DEXT, PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC, GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) \
x(void, glNamedFramebufferTexture3DEXT, PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC, GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) \
x(void, glNamedFramebufferRenderbufferEXT, PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC, GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) \
x(void, glGetNamedFramebufferAttachmentParameterivEXT, PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC, GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params) \
x(void, glGenerateTextureMipmapEXT, PFNGLGENERATETEXTUREMIPMAPEXTPROC, GLuint texture, GLenum target) \
x(void, glGenerateMultiTexMipmapEXT, PFNGLGENERATEMULTITEXMIPMAPEXTPROC, GLenum texunit, GLenum target) \
x(void, glFramebufferDrawBufferEXT, PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC, GLuint framebuffer, GLenum mode) \
x(void, glFramebufferDrawBuffersEXT, PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC, GLuint framebuffer, GLsizei n, const GLenum *bufs) \
x(void, glFramebufferReadBufferEXT, PFNGLFRAMEBUFFERREADBUFFEREXTPROC, GLuint framebuffer, GLenum mode) \
x(void, glGetFramebufferParameterivEXT, PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC, GLuint framebuffer, GLenum pname, GLint *params) \
x(void, glNamedCopyBufferSubDataEXT, PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) \
x(void, glNamedFramebufferTextureEXT, PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) \
x(void, glNamedFramebufferTextureLayerEXT, PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) \
x(void, glNamedFramebufferTextureFaceEXT, PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC, GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) \
x(void, glTextureRenderbufferEXT, PFNGLTEXTURERENDERBUFFEREXTPROC, GLuint texture, GLenum target, GLuint renderbuffer) \
x(void, glMultiTexRenderbufferEXT, PFNGLMULTITEXRENDERBUFFEREXTPROC, GLenum texunit, GLenum target, GLuint renderbuffer) \
x(void, glVertexArrayVertexOffsetEXT, PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayColorOffsetEXT, PFNGLVERTEXARRAYCOLOROFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayEdgeFlagOffsetEXT, PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayIndexOffsetEXT, PFNGLVERTEXARRAYINDEXOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayNormalOffsetEXT, PFNGLVERTEXARRAYNORMALOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayTexCoordOffsetEXT, PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayMultiTexCoordOffsetEXT, PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayFogCoordOffsetEXT, PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glVertexArraySecondaryColorOffsetEXT, PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayVertexAttribOffsetEXT, PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) \
x(void, glVertexArrayVertexAttribIOffsetEXT, PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glEnableVertexArrayEXT, PFNGLENABLEVERTEXARRAYEXTPROC, GLuint vaobj, GLenum array) \
x(void, glDisableVertexArrayEXT, PFNGLDISABLEVERTEXARRAYEXTPROC, GLuint vaobj, GLenum array) \
x(void, glEnableVertexArrayAttribEXT, PFNGLENABLEVERTEXARRAYATTRIBEXTPROC, GLuint vaobj, GLuint index) \
x(void, glDisableVertexArrayAttribEXT, PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC, GLuint vaobj, GLuint index) \
x(void, glGetVertexArrayIntegervEXT, PFNGLGETVERTEXARRAYINTEGERVEXTPROC, GLuint vaobj, GLenum pname, GLint *param) \
x(void, glGetVertexArrayPointervEXT, PFNGLGETVERTEXARRAYPOINTERVEXTPROC, GLuint vaobj, GLenum pname, void **param) \
x(void, glGetVertexArrayIntegeri_vEXT, PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC, GLuint vaobj, GLuint index, GLenum pname, GLint *param) \
x(void, glGetVertexArrayPointeri_vEXT, PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC, GLuint vaobj, GLuint index, GLenum pname, void **param) \
x(void, glFlushMappedNamedBufferRangeEXT, PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC, GLuint buffer, GLintptr offset, GLsizeiptr length) \
x(void, glNamedBufferStorageEXT, PFNGLNAMEDBUFFERSTORAGEEXTPROC, GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags) \
x(void, glClearNamedBufferDataEXT, PFNGLCLEARNAMEDBUFFERDATAEXTPROC, GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data) \
x(void, glClearNamedBufferSubDataEXT, PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC, GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data) \
x(void, glNamedFramebufferParameteriEXT, PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC, GLuint framebuffer, GLenum pname, GLint param) \
x(void, glGetNamedFramebufferParameterivEXT, PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC, GLuint framebuffer, GLenum pname, GLint *params) \
x(void, glProgramUniform1dEXT, PFNGLPROGRAMUNIFORM1DEXTPROC, GLuint program, GLint location, GLdouble x) \
x(void, glProgramUniform2dEXT, PFNGLPROGRAMUNIFORM2DEXTPROC, GLuint program, GLint location, GLdouble x, GLdouble y) \
x(void, glProgramUniform3dEXT, PFNGLPROGRAMUNIFORM3DEXTPROC, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) \
x(void, glProgramUniform4dEXT, PFNGLPROGRAMUNIFORM4DEXTPROC, GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glProgramUniform1dvEXT, PFNGLPROGRAMUNIFORM1DVEXTPROC, GLuint program, GLint location, GLsizei count, const GLdouble *value) \
x(void, glProgramUniform2dvEXT, PFNGLPROGRAMUNIFORM2DVEXTPROC, GLuint program, GLint location, GLsizei count, const GLdouble *value) \
x(void, glProgramUniform3dvEXT, PFNGLPROGRAMUNIFORM3DVEXTPROC, GLuint program, GLint location, GLsizei count, const GLdouble *value) \
x(void, glProgramUniform4dvEXT, PFNGLPROGRAMUNIFORM4DVEXTPROC, GLuint program, GLint location, GLsizei count, const GLdouble *value) \
x(void, glProgramUniformMatrix2dvEXT, PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix3dvEXT, PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix4dvEXT, PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix2x3dvEXT, PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix2x4dvEXT, PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix3x2dvEXT, PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix3x4dvEXT, PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix4x2dvEXT, PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glProgramUniformMatrix4x3dvEXT, PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC, GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value) \
x(void, glTextureBufferRangeEXT, PFNGLTEXTUREBUFFERRANGEEXTPROC, GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) \
x(void, glTextureStorage1DEXT, PFNGLTEXTURESTORAGE1DEXTPROC, GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) \
x(void, glTextureStorage2DEXT, PFNGLTEXTURESTORAGE2DEXTPROC, GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glTextureStorage3DEXT, PFNGLTEXTURESTORAGE3DEXTPROC, GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) \
x(void, glTextureStorage2DMultisampleEXT, PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC, GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) \
x(void, glTextureStorage3DMultisampleEXT, PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC, GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) \
x(void, glVertexArrayBindVertexBufferEXT, PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC, GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) \
x(void, glVertexArrayVertexAttribFormatEXT, PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) \
x(void, glVertexArrayVertexAttribIFormatEXT, PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) \
x(void, glVertexArrayVertexAttribLFormatEXT, PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC, GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) \
x(void, glVertexArrayVertexAttribBindingEXT, PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC, GLuint vaobj, GLuint attribindex, GLuint bindingindex) \
x(void, glVertexArrayVertexBindingDivisorEXT, PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC, GLuint vaobj, GLuint bindingindex, GLuint divisor) \
x(void, glVertexArrayVertexAttribLOffsetEXT, PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC, GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) \
x(void, glTexturePageCommitmentEXT, PFNGLTEXTUREPAGECOMMITMENTEXTPROC, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit) \
x(void, glVertexArrayVertexAttribDivisorEXT, PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC, GLuint vaobj, GLuint index, GLuint divisor) \
x(void, glColorMaskIndexedEXT, PFNGLCOLORMASKINDEXEDEXTPROC, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) \
x(void, glDrawArraysInstancedEXT, PFNGLDRAWARRAYSINSTANCEDEXTPROC, GLenum mode, GLint start, GLsizei count, GLsizei primcount) \
x(void, glDrawElementsInstancedEXT, PFNGLDRAWELEMENTSINSTANCEDEXTPROC, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount) \
x(void, glDrawRangeElementsEXT, PFNGLDRAWRANGEELEMENTSEXTPROC, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices) \
x(void, glBufferStorageExternalEXT, PFNGLBUFFERSTORAGEEXTERNALEXTPROC, GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags) \
x(void, glNamedBufferStorageExternalEXT, PFNGLNAMEDBUFFERSTORAGEEXTERNALEXTPROC, GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags) \
x(void, glFogCoordfEXT, PFNGLFOGCOORDFEXTPROC, GLfloat coord) \
x(void, glFogCoordfvEXT, PFNGLFOGCOORDFVEXTPROC, const GLfloat *coord) \
x(void, glFogCoorddEXT, PFNGLFOGCOORDDEXTPROC, GLdouble coord) \
x(void, glFogCoorddvEXT, PFNGLFOGCOORDDVEXTPROC, const GLdouble *coord) \
x(void, glFogCoordPointerEXT, PFNGLFOGCOORDPOINTEREXTPROC, GLenum type, GLsizei stride, const void *pointer) \
x(void, glBlitFramebufferEXT, PFNGLBLITFRAMEBUFFEREXTPROC, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) \
x(void, glRenderbufferStorageMultisampleEXT, PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) \
x(GLboolean, glIsRenderbufferEXT, PFNGLISRENDERBUFFEREXTPROC, GLuint renderbuffer) \
x(void, glBindRenderbufferEXT, PFNGLBINDRENDERBUFFEREXTPROC, GLenum target, GLuint renderbuffer) \
x(void, glDeleteRenderbuffersEXT, PFNGLDELETERENDERBUFFERSEXTPROC, GLsizei n, const GLuint *renderbuffers) \
x(void, glGenRenderbuffersEXT, PFNGLGENRENDERBUFFERSEXTPROC, GLsizei n, GLuint *renderbuffers) \
x(void, glRenderbufferStorageEXT, PFNGLRENDERBUFFERSTORAGEEXTPROC, GLenum target, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glGetRenderbufferParameterivEXT, PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC, GLenum target, GLenum pname, GLint *params) \
x(GLboolean, glIsFramebufferEXT, PFNGLISFRAMEBUFFEREXTPROC, GLuint framebuffer) \
x(void, glBindFramebufferEXT, PFNGLBINDFRAMEBUFFEREXTPROC, GLenum target, GLuint framebuffer) \
x(void, glDeleteFramebuffersEXT, PFNGLDELETEFRAMEBUFFERSEXTPROC, GLsizei n, const GLuint *framebuffers) \
x(void, glGenFramebuffersEXT, PFNGLGENFRAMEBUFFERSEXTPROC, GLsizei n, GLuint *framebuffers) \
x(GLenum, glCheckFramebufferStatusEXT, PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC, GLenum target) \
x(void, glFramebufferTexture1DEXT, PFNGLFRAMEBUFFERTEXTURE1DEXTPROC, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) \
x(void, glFramebufferTexture2DEXT, PFNGLFRAMEBUFFERTEXTURE2DEXTPROC, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) \
x(void, glFramebufferTexture3DEXT, PFNGLFRAMEBUFFERTEXTURE3DEXTPROC, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) \
x(void, glFramebufferRenderbufferEXT, PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) \
x(void, glGetFramebufferAttachmentParameterivEXT, PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC, GLenum target, GLenum attachment, GLenum pname, GLint *params) \
x(void, glGenerateMipmapEXT, PFNGLGENERATEMIPMAPEXTPROC, GLenum target) \
x(void, glProgramParameteriEXT, PFNGLPROGRAMPARAMETERIEXTPROC, GLuint program, GLenum pname, GLint value) \
x(void, glProgramEnvParameters4fvEXT, PFNGLPROGRAMENVPARAMETERS4FVEXTPROC, GLenum target, GLuint index, GLsizei count, const GLfloat *params) \
x(void, glProgramLocalParameters4fvEXT, PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC, GLenum target, GLuint index, GLsizei count, const GLfloat *params) \
x(void, glGetUniformuivEXT, PFNGLGETUNIFORMUIVEXTPROC, GLuint program, GLint location, GLuint *params) \
x(void, glBindFragDataLocationEXT, PFNGLBINDFRAGDATALOCATIONEXTPROC, GLuint program, GLuint color, const GLchar *name) \
x(GLint, glGetFragDataLocationEXT, PFNGLGETFRAGDATALOCATIONEXTPROC, GLuint program, const GLchar *name) \
x(void, glUniform1uiEXT, PFNGLUNIFORM1UIEXTPROC, GLint location, GLuint v0) \
x(void, glUniform2uiEXT, PFNGLUNIFORM2UIEXTPROC, GLint location, GLuint v0, GLuint v1) \
x(void, glUniform3uiEXT, PFNGLUNIFORM3UIEXTPROC, GLint location, GLuint v0, GLuint v1, GLuint v2) \
x(void, glUniform4uiEXT, PFNGLUNIFORM4UIEXTPROC, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) \
x(void, glUniform1uivEXT, PFNGLUNIFORM1UIVEXTPROC, GLint location, GLsizei count, const GLuint *value) \
x(void, glUniform2uivEXT, PFNGLUNIFORM2UIVEXTPROC, GLint location, GLsizei count, const GLuint *value) \
x(void, glUniform3uivEXT, PFNGLUNIFORM3UIVEXTPROC, GLint location, GLsizei count, const GLuint *value) \
x(void, glUniform4uivEXT, PFNGLUNIFORM4UIVEXTPROC, GLint location, GLsizei count, const GLuint *value) \
x(void, glVertexAttribI1iEXT, PFNGLVERTEXATTRIBI1IEXTPROC, GLuint index, GLint x) \
x(void, glVertexAttribI2iEXT, PFNGLVERTEXATTRIBI2IEXTPROC, GLuint index, GLint x, GLint y) \
x(void, glVertexAttribI3iEXT, PFNGLVERTEXATTRIBI3IEXTPROC, GLuint index, GLint x, GLint y, GLint z) \
x(void, glVertexAttribI4iEXT, PFNGLVERTEXATTRIBI4IEXTPROC, GLuint index, GLint x, GLint y, GLint z, GLint w) \
x(void, glVertexAttribI1uiEXT, PFNGLVERTEXATTRIBI1UIEXTPROC, GLuint index, GLuint x) \
x(void, glVertexAttribI2uiEXT, PFNGLVERTEXATTRIBI2UIEXTPROC, GLuint index, GLuint x, GLuint y) \
x(void, glVertexAttribI3uiEXT, PFNGLVERTEXATTRIBI3UIEXTPROC, GLuint index, GLuint x, GLuint y, GLuint z) \
x(void, glVertexAttribI4uiEXT, PFNGLVERTEXATTRIBI4UIEXTPROC, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) \
x(void, glVertexAttribI1ivEXT, PFNGLVERTEXATTRIBI1IVEXTPROC, GLuint index, const GLint *v) \
x(void, glVertexAttribI2ivEXT, PFNGLVERTEXATTRIBI2IVEXTPROC, GLuint index, const GLint *v) \
x(void, glVertexAttribI3ivEXT, PFNGLVERTEXATTRIBI3IVEXTPROC, GLuint index, const GLint *v) \
x(void, glVertexAttribI4ivEXT, PFNGLVERTEXATTRIBI4IVEXTPROC, GLuint index, const GLint *v) \
x(void, glVertexAttribI1uivEXT, PFNGLVERTEXATTRIBI1UIVEXTPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttribI2uivEXT, PFNGLVERTEXATTRIBI2UIVEXTPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttribI3uivEXT, PFNGLVERTEXATTRIBI3UIVEXTPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttribI4uivEXT, PFNGLVERTEXATTRIBI4UIVEXTPROC, GLuint index, const GLuint *v) \
x(void, glVertexAttribI4bvEXT, PFNGLVERTEXATTRIBI4BVEXTPROC, GLuint index, const GLbyte *v) \
x(void, glVertexAttribI4svEXT, PFNGLVERTEXATTRIBI4SVEXTPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttribI4ubvEXT, PFNGLVERTEXATTRIBI4UBVEXTPROC, GLuint index, const GLubyte *v) \
x(void, glVertexAttribI4usvEXT, PFNGLVERTEXATTRIBI4USVEXTPROC, GLuint index, const GLushort *v) \
x(void, glVertexAttribIPointerEXT, PFNGLVERTEXATTRIBIPOINTEREXTPROC, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glGetVertexAttribIivEXT, PFNGLGETVERTEXATTRIBIIVEXTPROC, GLuint index, GLenum pname, GLint *params) \
x(void, glGetVertexAttribIuivEXT, PFNGLGETVERTEXATTRIBIUIVEXTPROC, GLuint index, GLenum pname, GLuint *params) \
x(void, glGetHistogramEXT, PFNGLGETHISTOGRAMEXTPROC, GLenum target, GLboolean reset, GLenum format, GLenum type, void *values) \
x(void, glGetHistogramParameterfvEXT, PFNGLGETHISTOGRAMPARAMETERFVEXTPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetHistogramParameterivEXT, PFNGLGETHISTOGRAMPARAMETERIVEXTPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetMinmaxEXT, PFNGLGETMINMAXEXTPROC, GLenum target, GLboolean reset, GLenum format, GLenum type, void *values) \
x(void, glGetMinmaxParameterfvEXT, PFNGLGETMINMAXPARAMETERFVEXTPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetMinmaxParameterivEXT, PFNGLGETMINMAXPARAMETERIVEXTPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glHistogramEXT, PFNGLHISTOGRAMEXTPROC, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) \
x(void, glMinmaxEXT, PFNGLMINMAXEXTPROC, GLenum target, GLenum internalformat, GLboolean sink) \
x(void, glResetHistogramEXT, PFNGLRESETHISTOGRAMEXTPROC, GLenum target) \
x(void, glResetMinmaxEXT, PFNGLRESETMINMAXEXTPROC, GLenum target) \
x(void, glIndexFuncEXT, PFNGLINDEXFUNCEXTPROC, GLenum func, GLclampf ref) \
x(void, glIndexMaterialEXT, PFNGLINDEXMATERIALEXTPROC, GLenum face, GLenum mode) \
x(void, glApplyTextureEXT, PFNGLAPPLYTEXTUREEXTPROC, GLenum mode) \
x(void, glTextureLightEXT, PFNGLTEXTURELIGHTEXTPROC, GLenum pname) \
x(void, glTextureMaterialEXT, PFNGLTEXTUREMATERIALEXTPROC, GLenum face, GLenum mode) \
x(void, glGetUnsignedBytevEXT, PFNGLGETUNSIGNEDBYTEVEXTPROC, GLenum pname, GLubyte *data) \
x(void, glGetUnsignedBytei_vEXT, PFNGLGETUNSIGNEDBYTEI_VEXTPROC, GLenum target, GLuint index, GLubyte *data) \
x(void, glDeleteMemoryObjectsEXT, PFNGLDELETEMEMORYOBJECTSEXTPROC, GLsizei n, const GLuint *memoryObjects) \
x(GLboolean, glIsMemoryObjectEXT, PFNGLISMEMORYOBJECTEXTPROC, GLuint memoryObject) \
x(void, glCreateMemoryObjectsEXT, PFNGLCREATEMEMORYOBJECTSEXTPROC, GLsizei n, GLuint *memoryObjects) \
x(void, glMemoryObjectParameterivEXT, PFNGLMEMORYOBJECTPARAMETERIVEXTPROC, GLuint memoryObject, GLenum pname, const GLint *params) \
x(void, glGetMemoryObjectParameterivEXT, PFNGLGETMEMORYOBJECTPARAMETERIVEXTPROC, GLuint memoryObject, GLenum pname, GLint *params) \
x(void, glTexStorageMem2DEXT, PFNGLTEXSTORAGEMEM2DEXTPROC, GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset) \
x(void, glTexStorageMem2DMultisampleEXT, PFNGLTEXSTORAGEMEM2DMULTISAMPLEEXTPROC, GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) \
x(void, glTexStorageMem3DEXT, PFNGLTEXSTORAGEMEM3DEXTPROC, GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset) \
x(void, glTexStorageMem3DMultisampleEXT, PFNGLTEXSTORAGEMEM3DMULTISAMPLEEXTPROC, GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) \
x(void, glBufferStorageMemEXT, PFNGLBUFFERSTORAGEMEMEXTPROC, GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset) \
x(void, glTextureStorageMem2DEXT, PFNGLTEXTURESTORAGEMEM2DEXTPROC, GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset) \
x(void, glTextureStorageMem2DMultisampleEXT, PFNGLTEXTURESTORAGEMEM2DMULTISAMPLEEXTPROC, GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) \
x(void, glTextureStorageMem3DEXT, PFNGLTEXTURESTORAGEMEM3DEXTPROC, GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset) \
x(void, glTextureStorageMem3DMultisampleEXT, PFNGLTEXTURESTORAGEMEM3DMULTISAMPLEEXTPROC, GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset) \
x(void, glNamedBufferStorageMemEXT, PFNGLNAMEDBUFFERSTORAGEMEMEXTPROC, GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset) \
x(void, glTexStorageMem1DEXT, PFNGLTEXSTORAGEMEM1DEXTPROC, GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset) \
x(void, glTextureStorageMem1DEXT, PFNGLTEXTURESTORAGEMEM1DEXTPROC, GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset) \
x(void, glImportMemoryFdEXT, PFNGLIMPORTMEMORYFDEXTPROC, GLuint memory, GLuint64 size, GLenum handleType, GLint fd) \
x(void, glImportMemoryWin32HandleEXT, PFNGLIMPORTMEMORYWIN32HANDLEEXTPROC, GLuint memory, GLuint64 size, GLenum handleType, void *handle) \
x(void, glImportMemoryWin32NameEXT, PFNGLIMPORTMEMORYWIN32NAMEEXTPROC, GLuint memory, GLuint64 size, GLenum handleType, const void *name) \
x(void, glMultiDrawArraysEXT, PFNGLMULTIDRAWARRAYSEXTPROC, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount) \
x(void, glMultiDrawElementsEXT, PFNGLMULTIDRAWELEMENTSEXTPROC, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount) \
x(void, glSampleMaskEXT, PFNGLSAMPLEMASKEXTPROC, GLclampf value, GLboolean invert) \
x(void, glSamplePatternEXT, PFNGLSAMPLEPATTERNEXTPROC, GLenum pattern) \
x(void, glColorTableEXT, PFNGLCOLORTABLEEXTPROC, GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *table) \
x(void, glGetColorTableEXT, PFNGLGETCOLORTABLEEXTPROC, GLenum target, GLenum format, GLenum type, void *data) \
x(void, glGetColorTableParameterivEXT, PFNGLGETCOLORTABLEPARAMETERIVEXTPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetColorTableParameterfvEXT, PFNGLGETCOLORTABLEPARAMETERFVEXTPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glPixelTransformParameteriEXT, PFNGLPIXELTRANSFORMPARAMETERIEXTPROC, GLenum target, GLenum pname, GLint param) \
x(void, glPixelTransformParameterfEXT, PFNGLPIXELTRANSFORMPARAMETERFEXTPROC, GLenum target, GLenum pname, GLfloat param) \
x(void, glPixelTransformParameterivEXT, PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glPixelTransformParameterfvEXT, PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glGetPixelTransformParameterivEXT, PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetPixelTransformParameterfvEXT, PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glPointParameterfEXT, PFNGLPOINTPARAMETERFEXTPROC, GLenum pname, GLfloat param) \
x(void, glPointParameterfvEXT, PFNGLPOINTPARAMETERFVEXTPROC, GLenum pname, const GLfloat *params) \
x(void, glPolygonOffsetEXT, PFNGLPOLYGONOFFSETEXTPROC, GLfloat factor, GLfloat bias) \
x(void, glPolygonOffsetClampEXT, PFNGLPOLYGONOFFSETCLAMPEXTPROC, GLfloat factor, GLfloat units, GLfloat clamp) \
x(void, glProvokingVertexEXT, PFNGLPROVOKINGVERTEXEXTPROC, GLenum mode) \
x(void, glRasterSamplesEXT, PFNGLRASTERSAMPLESEXTPROC, GLuint samples, GLboolean fixedsamplelocations) \
x(void, glSecondaryColor3bEXT, PFNGLSECONDARYCOLOR3BEXTPROC, GLbyte red, GLbyte green, GLbyte blue) \
x(void, glSecondaryColor3bvEXT, PFNGLSECONDARYCOLOR3BVEXTPROC, const GLbyte *v) \
x(void, glSecondaryColor3dEXT, PFNGLSECONDARYCOLOR3DEXTPROC, GLdouble red, GLdouble green, GLdouble blue) \
x(void, glSecondaryColor3dvEXT, PFNGLSECONDARYCOLOR3DVEXTPROC, const GLdouble *v) \
x(void, glSecondaryColor3fEXT, PFNGLSECONDARYCOLOR3FEXTPROC, GLfloat red, GLfloat green, GLfloat blue) \
x(void, glSecondaryColor3fvEXT, PFNGLSECONDARYCOLOR3FVEXTPROC, const GLfloat *v) \
x(void, glSecondaryColor3iEXT, PFNGLSECONDARYCOLOR3IEXTPROC, GLint red, GLint green, GLint blue) \
x(void, glSecondaryColor3ivEXT, PFNGLSECONDARYCOLOR3IVEXTPROC, const GLint *v) \
x(void, glSecondaryColor3sEXT, PFNGLSECONDARYCOLOR3SEXTPROC, GLshort red, GLshort green, GLshort blue) \
x(void, glSecondaryColor3svEXT, PFNGLSECONDARYCOLOR3SVEXTPROC, const GLshort *v) \
x(void, glSecondaryColor3ubEXT, PFNGLSECONDARYCOLOR3UBEXTPROC, GLubyte red, GLubyte green, GLubyte blue) \
x(void, glSecondaryColor3ubvEXT, PFNGLSECONDARYCOLOR3UBVEXTPROC, const GLubyte *v) \
x(void, glSecondaryColor3uiEXT, PFNGLSECONDARYCOLOR3UIEXTPROC, GLuint red, GLuint green, GLuint blue) \
x(void, glSecondaryColor3uivEXT, PFNGLSECONDARYCOLOR3UIVEXTPROC, const GLuint *v) \
x(void, glSecondaryColor3usEXT, PFNGLSECONDARYCOLOR3USEXTPROC, GLushort red, GLushort green, GLushort blue) \
x(void, glSecondaryColor3usvEXT, PFNGLSECONDARYCOLOR3USVEXTPROC, const GLushort *v) \
x(void, glSecondaryColorPointerEXT, PFNGLSECONDARYCOLORPOINTEREXTPROC, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glGenSemaphoresEXT, PFNGLGENSEMAPHORESEXTPROC, GLsizei n, GLuint *semaphores) \
x(void, glDeleteSemaphoresEXT, PFNGLDELETESEMAPHORESEXTPROC, GLsizei n, const GLuint *semaphores) \
x(GLboolean, glIsSemaphoreEXT, PFNGLISSEMAPHOREEXTPROC, GLuint semaphore) \
x(void, glSemaphoreParameterui64vEXT, PFNGLSEMAPHOREPARAMETERUI64VEXTPROC, GLuint semaphore, GLenum pname, const GLuint64 *params) \
x(void, glGetSemaphoreParameterui64vEXT, PFNGLGETSEMAPHOREPARAMETERUI64VEXTPROC, GLuint semaphore, GLenum pname, GLuint64 *params) \
x(void, glWaitSemaphoreEXT, PFNGLWAITSEMAPHOREEXTPROC, GLuint semaphore, GLuint numBufferBarriers, const GLuint *buffers, GLuint numTextureBarriers, const GLuint *textures, const GLenum *srcLayouts) \
x(void, glSignalSemaphoreEXT, PFNGLSIGNALSEMAPHOREEXTPROC, GLuint semaphore, GLuint numBufferBarriers, const GLuint *buffers, GLuint numTextureBarriers, const GLuint *textures, const GLenum *dstLayouts) \
x(void, glImportSemaphoreFdEXT, PFNGLIMPORTSEMAPHOREFDEXTPROC, GLuint semaphore, GLenum handleType, GLint fd) \
x(void, glImportSemaphoreWin32HandleEXT, PFNGLIMPORTSEMAPHOREWIN32HANDLEEXTPROC, GLuint semaphore, GLenum handleType, void *handle) \
x(void, glImportSemaphoreWin32NameEXT, PFNGLIMPORTSEMAPHOREWIN32NAMEEXTPROC, GLuint semaphore, GLenum handleType, const void *name) \
x(void, glUseShaderProgramEXT, PFNGLUSESHADERPROGRAMEXTPROC, GLenum type, GLuint program) \
x(void, glActiveProgramEXT, PFNGLACTIVEPROGRAMEXTPROC, GLuint program) \
x(GLuint, glCreateShaderProgramEXT, PFNGLCREATESHADERPROGRAMEXTPROC, GLenum type, const GLchar *string) \
x(void, glFramebufferFetchBarrierEXT, PFNGLFRAMEBUFFERFETCHBARRIEREXTPROC, void) \
x(void, glBindImageTextureEXT, PFNGLBINDIMAGETEXTUREEXTPROC, GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) \
x(void, glMemoryBarrierEXT, PFNGLMEMORYBARRIEREXTPROC, GLbitfield barriers) \
x(void, glStencilClearTagEXT, PFNGLSTENCILCLEARTAGEXTPROC, GLsizei stencilTagBits, GLuint stencilClearTag) \
x(void, glActiveStencilFaceEXT, PFNGLACTIVESTENCILFACEEXTPROC, GLenum face) \
x(void, glTexSubImage1DEXT, PFNGLTEXSUBIMAGE1DEXTPROC, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels) \
x(void, glTexSubImage2DEXT, PFNGLTEXSUBIMAGE2DEXTPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels) \
x(void, glTexImage3DEXT, PFNGLTEXIMAGE3DEXTPROC, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glTexSubImage3DEXT, PFNGLTEXSUBIMAGE3DEXTPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels) \
x(void, glFramebufferTextureLayerEXT, PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) \
x(void, glTexBufferEXT, PFNGLTEXBUFFEREXTPROC, GLenum target, GLenum internalformat, GLuint buffer) \
x(void, glTexParameterIivEXT, PFNGLTEXPARAMETERIIVEXTPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glTexParameterIuivEXT, PFNGLTEXPARAMETERIUIVEXTPROC, GLenum target, GLenum pname, const GLuint *params) \
x(void, glGetTexParameterIivEXT, PFNGLGETTEXPARAMETERIIVEXTPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetTexParameterIuivEXT, PFNGLGETTEXPARAMETERIUIVEXTPROC, GLenum target, GLenum pname, GLuint *params) \
x(void, glClearColorIiEXT, PFNGLCLEARCOLORIIEXTPROC, GLint red, GLint green, GLint blue, GLint alpha) \
x(void, glClearColorIuiEXT, PFNGLCLEARCOLORIUIEXTPROC, GLuint red, GLuint green, GLuint blue, GLuint alpha) \
x(GLboolean, glAreTexturesResidentEXT, PFNGLARETEXTURESRESIDENTEXTPROC, GLsizei n, const GLuint *textures, GLboolean *residences) \
x(void, glBindTextureEXT, PFNGLBINDTEXTUREEXTPROC, GLenum target, GLuint texture) \
x(void, glDeleteTexturesEXT, PFNGLDELETETEXTURESEXTPROC, GLsizei n, const GLuint *textures) \
x(void, glGenTexturesEXT, PFNGLGENTEXTURESEXTPROC, GLsizei n, GLuint *textures) \
x(GLboolean, glIsTextureEXT, PFNGLISTEXTUREEXTPROC, GLuint texture) \
x(void, glPrioritizeTexturesEXT, PFNGLPRIORITIZETEXTURESEXTPROC, GLsizei n, const GLuint *textures, const GLclampf *priorities) \
x(void, glTextureNormalEXT, PFNGLTEXTURENORMALEXTPROC, GLenum mode) \
x(void, glTexStorage1DEXT, PFNGLTEXSTORAGE1DEXTPROC, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) \
x(void, glTexStorage2DEXT, PFNGLTEXSTORAGE2DEXTPROC, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glTexStorage3DEXT, PFNGLTEXSTORAGE3DEXTPROC, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) \
x(void, glGetQueryObjecti64vEXT, PFNGLGETQUERYOBJECTI64VEXTPROC, GLuint id, GLenum pname, GLint64 *params) \
x(void, glGetQueryObjectui64vEXT, PFNGLGETQUERYOBJECTUI64VEXTPROC, GLuint id, GLenum pname, GLuint64 *params) \
x(void, glBeginTransformFeedbackEXT, PFNGLBEGINTRANSFORMFEEDBACKEXTPROC, GLenum primitiveMode) \
x(void, glEndTransformFeedbackEXT, PFNGLENDTRANSFORMFEEDBACKEXTPROC, void) \
x(void, glBindBufferRangeEXT, PFNGLBINDBUFFERRANGEEXTPROC, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) \
x(void, glBindBufferOffsetEXT, PFNGLBINDBUFFEROFFSETEXTPROC, GLenum target, GLuint index, GLuint buffer, GLintptr offset) \
x(void, glBindBufferBaseEXT, PFNGLBINDBUFFERBASEEXTPROC, GLenum target, GLuint index, GLuint buffer) \
x(void, glTransformFeedbackVaryingsEXT, PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC, GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode) \
x(void, glGetTransformFeedbackVaryingEXT, PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) \
x(void, glArrayElementEXT, PFNGLARRAYELEMENTEXTPROC, GLint i) \
x(void, glColorPointerEXT, PFNGLCOLORPOINTEREXTPROC, GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer) \
x(void, glDrawArraysEXT, PFNGLDRAWARRAYSEXTPROC, GLenum mode, GLint first, GLsizei count) \
x(void, glEdgeFlagPointerEXT, PFNGLEDGEFLAGPOINTEREXTPROC, GLsizei stride, GLsizei count, const GLboolean *pointer) \
x(void, glGetPointervEXT, PFNGLGETPOINTERVEXTPROC, GLenum pname, void **params) \
x(void, glIndexPointerEXT, PFNGLINDEXPOINTEREXTPROC, GLenum type, GLsizei stride, GLsizei count, const void *pointer) \
x(void, glNormalPointerEXT, PFNGLNORMALPOINTEREXTPROC, GLenum type, GLsizei stride, GLsizei count, const void *pointer) \
x(void, glTexCoordPointerEXT, PFNGLTEXCOORDPOINTEREXTPROC, GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer) \
x(void, glVertexPointerEXT, PFNGLVERTEXPOINTEREXTPROC, GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer) \
x(void, glVertexAttribL1dEXT, PFNGLVERTEXATTRIBL1DEXTPROC, GLuint index, GLdouble x) \
x(void, glVertexAttribL2dEXT, PFNGLVERTEXATTRIBL2DEXTPROC, GLuint index, GLdouble x, GLdouble y) \
x(void, glVertexAttribL3dEXT, PFNGLVERTEXATTRIBL3DEXTPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z) \
x(void, glVertexAttribL4dEXT, PFNGLVERTEXATTRIBL4DEXTPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glVertexAttribL1dvEXT, PFNGLVERTEXATTRIBL1DVEXTPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttribL2dvEXT, PFNGLVERTEXATTRIBL2DVEXTPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttribL3dvEXT, PFNGLVERTEXATTRIBL3DVEXTPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttribL4dvEXT, PFNGLVERTEXATTRIBL4DVEXTPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttribLPointerEXT, PFNGLVERTEXATTRIBLPOINTEREXTPROC, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(void, glGetVertexAttribLdvEXT, PFNGLGETVERTEXATTRIBLDVEXTPROC, GLuint index, GLenum pname, GLdouble *params) \
x(void, glBeginVertexShaderEXT, PFNGLBEGINVERTEXSHADEREXTPROC, void) \
x(void, glEndVertexShaderEXT, PFNGLENDVERTEXSHADEREXTPROC, void) \
x(void, glBindVertexShaderEXT, PFNGLBINDVERTEXSHADEREXTPROC, GLuint id) \
x(GLuint, glGenVertexShadersEXT, PFNGLGENVERTEXSHADERSEXTPROC, GLuint range) \
x(void, glDeleteVertexShaderEXT, PFNGLDELETEVERTEXSHADEREXTPROC, GLuint id) \
x(void, glShaderOp1EXT, PFNGLSHADEROP1EXTPROC, GLenum op, GLuint res, GLuint arg1) \
x(void, glShaderOp2EXT, PFNGLSHADEROP2EXTPROC, GLenum op, GLuint res, GLuint arg1, GLuint arg2) \
x(void, glShaderOp3EXT, PFNGLSHADEROP3EXTPROC, GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3) \
x(void, glSwizzleEXT, PFNGLSWIZZLEEXTPROC, GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) \
x(void, glWriteMaskEXT, PFNGLWRITEMASKEXTPROC, GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) \
x(void, glInsertComponentEXT, PFNGLINSERTCOMPONENTEXTPROC, GLuint res, GLuint src, GLuint num) \
x(void, glExtractComponentEXT, PFNGLEXTRACTCOMPONENTEXTPROC, GLuint res, GLuint src, GLuint num) \
x(GLuint, glGenSymbolsEXT, PFNGLGENSYMBOLSEXTPROC, GLenum datatype, GLenum storagetype, GLenum range, GLuint components) \
x(void, glSetInvariantEXT, PFNGLSETINVARIANTEXTPROC, GLuint id, GLenum type, const void *addr) \
x(void, glSetLocalConstantEXT, PFNGLSETLOCALCONSTANTEXTPROC, GLuint id, GLenum type, const void *addr) \
x(void, glVariantbvEXT, PFNGLVARIANTBVEXTPROC, GLuint id, const GLbyte *addr) \
x(void, glVariantsvEXT, PFNGLVARIANTSVEXTPROC, GLuint id, const GLshort *addr) \
x(void, glVariantivEXT, PFNGLVARIANTIVEXTPROC, GLuint id, const GLint *addr) \
x(void, glVariantfvEXT, PFNGLVARIANTFVEXTPROC, GLuint id, const GLfloat *addr) \
x(void, glVariantdvEXT, PFNGLVARIANTDVEXTPROC, GLuint id, const GLdouble *addr) \
x(void, glVariantubvEXT, PFNGLVARIANTUBVEXTPROC, GLuint id, const GLubyte *addr) \
x(void, glVariantusvEXT, PFNGLVARIANTUSVEXTPROC, GLuint id, const GLushort *addr) \
x(void, glVariantuivEXT, PFNGLVARIANTUIVEXTPROC, GLuint id, const GLuint *addr) \
x(void, glVariantPointerEXT, PFNGLVARIANTPOINTEREXTPROC, GLuint id, GLenum type, GLuint stride, const void *addr) \
x(void, glEnableVariantClientStateEXT, PFNGLENABLEVARIANTCLIENTSTATEEXTPROC, GLuint id) \
x(void, glDisableVariantClientStateEXT, PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC, GLuint id) \
x(GLuint, glBindLightParameterEXT, PFNGLBINDLIGHTPARAMETEREXTPROC, GLenum light, GLenum value) \
x(GLuint, glBindMaterialParameterEXT, PFNGLBINDMATERIALPARAMETEREXTPROC, GLenum face, GLenum value) \
x(GLuint, glBindTexGenParameterEXT, PFNGLBINDTEXGENPARAMETEREXTPROC, GLenum unit, GLenum coord, GLenum value) \
x(GLuint, glBindTextureUnitParameterEXT, PFNGLBINDTEXTUREUNITPARAMETEREXTPROC, GLenum unit, GLenum value) \
x(GLuint, glBindParameterEXT, PFNGLBINDPARAMETEREXTPROC, GLenum value) \
x(GLboolean, glIsVariantEnabledEXT, PFNGLISVARIANTENABLEDEXTPROC, GLuint id, GLenum cap) \
x(void, glGetVariantBooleanvEXT, PFNGLGETVARIANTBOOLEANVEXTPROC, GLuint id, GLenum value, GLboolean *data) \
x(void, glGetVariantIntegervEXT, PFNGLGETVARIANTINTEGERVEXTPROC, GLuint id, GLenum value, GLint *data) \
x(void, glGetVariantFloatvEXT, PFNGLGETVARIANTFLOATVEXTPROC, GLuint id, GLenum value, GLfloat *data) \
x(void, glGetVariantPointervEXT, PFNGLGETVARIANTPOINTERVEXTPROC, GLuint id, GLenum value, void **data) \
x(void, glGetInvariantBooleanvEXT, PFNGLGETINVARIANTBOOLEANVEXTPROC, GLuint id, GLenum value, GLboolean *data) \
x(void, glGetInvariantIntegervEXT, PFNGLGETINVARIANTINTEGERVEXTPROC, GLuint id, GLenum value, GLint *data) \
x(void, glGetInvariantFloatvEXT, PFNGLGETINVARIANTFLOATVEXTPROC, GLuint id, GLenum value, GLfloat *data) \
x(void, glGetLocalConstantBooleanvEXT, PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC, GLuint id, GLenum value, GLboolean *data) \
x(void, glGetLocalConstantIntegervEXT, PFNGLGETLOCALCONSTANTINTEGERVEXTPROC, GLuint id, GLenum value, GLint *data) \
x(void, glGetLocalConstantFloatvEXT, PFNGLGETLOCALCONSTANTFLOATVEXTPROC, GLuint id, GLenum value, GLfloat *data) \
x(void, glVertexWeightfEXT, PFNGLVERTEXWEIGHTFEXTPROC, GLfloat weight) \
x(void, glVertexWeightfvEXT, PFNGLVERTEXWEIGHTFVEXTPROC, const GLfloat *weight) \
x(void, glVertexWeightPointerEXT, PFNGLVERTEXWEIGHTPOINTEREXTPROC, GLint size, GLenum type, GLsizei stride, const void *pointer) \
x(GLboolean, glAcquireKeyedMutexWin32EXT, PFNGLACQUIREKEYEDMUTEXWIN32EXTPROC, GLuint memory, GLuint64 key, GLuint timeout) \
x(GLboolean, glReleaseKeyedMutexWin32EXT, PFNGLRELEASEKEYEDMUTEXWIN32EXTPROC, GLuint memory, GLuint64 key) \
x(void, glWindowRectanglesEXT, PFNGLWINDOWRECTANGLESEXTPROC, GLenum mode, GLsizei count, const GLint *box) \
x(GLsync, glImportSyncEXT, PFNGLIMPORTSYNCEXTPROC, GLenum external_sync_type, GLintptr external_sync, GLbitfield flags) \
x(void, glFrameTerminatorGREMEDY, PFNGLFRAMETERMINATORGREMEDYPROC, void) \
x(void, glStringMarkerGREMEDY, PFNGLSTRINGMARKERGREMEDYPROC, GLsizei len, const void *string) \
x(void, glImageTransformParameteriHP, PFNGLIMAGETRANSFORMPARAMETERIHPPROC, GLenum target, GLenum pname, GLint param) \
x(void, glImageTransformParameterfHP, PFNGLIMAGETRANSFORMPARAMETERFHPPROC, GLenum target, GLenum pname, GLfloat param) \
x(void, glImageTransformParameterivHP, PFNGLIMAGETRANSFORMPARAMETERIVHPPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glImageTransformParameterfvHP, PFNGLIMAGETRANSFORMPARAMETERFVHPPROC, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glGetImageTransformParameterivHP, PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetImageTransformParameterfvHP, PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glMultiModeDrawArraysIBM, PFNGLMULTIMODEDRAWARRAYSIBMPROC, const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride) \
x(void, glMultiModeDrawElementsIBM, PFNGLMULTIMODEDRAWELEMENTSIBMPROC, const GLenum *mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, GLint modestride) \
x(void, glFlushStaticDataIBM, PFNGLFLUSHSTATICDATAIBMPROC, GLenum target) \
x(void, glColorPointerListIBM, PFNGLCOLORPOINTERLISTIBMPROC, GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride) \
x(void, glSecondaryColorPointerListIBM, PFNGLSECONDARYCOLORPOINTERLISTIBMPROC, GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride) \
x(void, glEdgeFlagPointerListIBM, PFNGLEDGEFLAGPOINTERLISTIBMPROC, GLint stride, const GLboolean **pointer, GLint ptrstride) \
x(void, glFogCoordPointerListIBM, PFNGLFOGCOORDPOINTERLISTIBMPROC, GLenum type, GLint stride, const void **pointer, GLint ptrstride) \
x(void, glIndexPointerListIBM, PFNGLINDEXPOINTERLISTIBMPROC, GLenum type, GLint stride, const void **pointer, GLint ptrstride) \
x(void, glNormalPointerListIBM, PFNGLNORMALPOINTERLISTIBMPROC, GLenum type, GLint stride, const void **pointer, GLint ptrstride) \
x(void, glTexCoordPointerListIBM, PFNGLTEXCOORDPOINTERLISTIBMPROC, GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride) \
x(void, glVertexPointerListIBM, PFNGLVERTEXPOINTERLISTIBMPROC, GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride) \
x(void, glBlendFuncSeparateINGR, PFNGLBLENDFUNCSEPARATEINGRPROC, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) \
x(void, glApplyFramebufferAttachmentCMAAINTEL, PFNGLAPPLYFRAMEBUFFERATTACHMENTCMAAINTELPROC, void) \
x(void, glSyncTextureINTEL, PFNGLSYNCTEXTUREINTELPROC, GLuint texture) \
x(void, glUnmapTexture2DINTEL, PFNGLUNMAPTEXTURE2DINTELPROC, GLuint texture, GLint level) \
x(void, glVertexPointervINTEL, PFNGLVERTEXPOINTERVINTELPROC, GLint size, GLenum type, const void **pointer) \
x(void, glNormalPointervINTEL, PFNGLNORMALPOINTERVINTELPROC, GLenum type, const void **pointer) \
x(void, glColorPointervINTEL, PFNGLCOLORPOINTERVINTELPROC, GLint size, GLenum type, const void **pointer) \
x(void, glTexCoordPointervINTEL, PFNGLTEXCOORDPOINTERVINTELPROC, GLint size, GLenum type, const void **pointer) \
x(void, glBeginPerfQueryINTEL, PFNGLBEGINPERFQUERYINTELPROC, GLuint queryHandle) \
x(void, glCreatePerfQueryINTEL, PFNGLCREATEPERFQUERYINTELPROC, GLuint queryId, GLuint *queryHandle) \
x(void, glDeletePerfQueryINTEL, PFNGLDELETEPERFQUERYINTELPROC, GLuint queryHandle) \
x(void, glEndPerfQueryINTEL, PFNGLENDPERFQUERYINTELPROC, GLuint queryHandle) \
x(void, glGetFirstPerfQueryIdINTEL, PFNGLGETFIRSTPERFQUERYIDINTELPROC, GLuint *queryId) \
x(void, glGetNextPerfQueryIdINTEL, PFNGLGETNEXTPERFQUERYIDINTELPROC, GLuint queryId, GLuint *nextQueryId) \
x(void, glGetPerfCounterInfoINTEL, PFNGLGETPERFCOUNTERINFOINTELPROC, GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue) \
x(void, glGetPerfQueryDataINTEL, PFNGLGETPERFQUERYDATAINTELPROC, GLuint queryHandle, GLuint flags, GLsizei dataSize, void *data, GLuint *bytesWritten) \
x(void, glGetPerfQueryIdByNameINTEL, PFNGLGETPERFQUERYIDBYNAMEINTELPROC, GLchar *queryName, GLuint *queryId) \
x(void, glGetPerfQueryInfoINTEL, PFNGLGETPERFQUERYINFOINTELPROC, GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask) \
x(void, glFramebufferParameteriMESA, PFNGLFRAMEBUFFERPARAMETERIMESAPROC, GLenum target, GLenum pname, GLint param) \
x(void, glGetFramebufferParameterivMESA, PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glResizeBuffersMESA, PFNGLRESIZEBUFFERSMESAPROC, void) \
x(void, glWindowPos2dMESA, PFNGLWINDOWPOS2DMESAPROC, GLdouble x, GLdouble y) \
x(void, glWindowPos2dvMESA, PFNGLWINDOWPOS2DVMESAPROC, const GLdouble *v) \
x(void, glWindowPos2fMESA, PFNGLWINDOWPOS2FMESAPROC, GLfloat x, GLfloat y) \
x(void, glWindowPos2fvMESA, PFNGLWINDOWPOS2FVMESAPROC, const GLfloat *v) \
x(void, glWindowPos2iMESA, PFNGLWINDOWPOS2IMESAPROC, GLint x, GLint y) \
x(void, glWindowPos2ivMESA, PFNGLWINDOWPOS2IVMESAPROC, const GLint *v) \
x(void, glWindowPos2sMESA, PFNGLWINDOWPOS2SMESAPROC, GLshort x, GLshort y) \
x(void, glWindowPos2svMESA, PFNGLWINDOWPOS2SVMESAPROC, const GLshort *v) \
x(void, glWindowPos3dMESA, PFNGLWINDOWPOS3DMESAPROC, GLdouble x, GLdouble y, GLdouble z) \
x(void, glWindowPos3dvMESA, PFNGLWINDOWPOS3DVMESAPROC, const GLdouble *v) \
x(void, glWindowPos3fMESA, PFNGLWINDOWPOS3FMESAPROC, GLfloat x, GLfloat y, GLfloat z) \
x(void, glWindowPos3fvMESA, PFNGLWINDOWPOS3FVMESAPROC, const GLfloat *v) \
x(void, glWindowPos3iMESA, PFNGLWINDOWPOS3IMESAPROC, GLint x, GLint y, GLint z) \
x(void, glWindowPos3ivMESA, PFNGLWINDOWPOS3IVMESAPROC, const GLint *v) \
x(void, glWindowPos3sMESA, PFNGLWINDOWPOS3SMESAPROC, GLshort x, GLshort y, GLshort z) \
x(void, glWindowPos3svMESA, PFNGLWINDOWPOS3SVMESAPROC, const GLshort *v) \
x(void, glWindowPos4dMESA, PFNGLWINDOWPOS4DMESAPROC, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glWindowPos4dvMESA, PFNGLWINDOWPOS4DVMESAPROC, const GLdouble *v) \
x(void, glWindowPos4fMESA, PFNGLWINDOWPOS4FMESAPROC, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glWindowPos4fvMESA, PFNGLWINDOWPOS4FVMESAPROC, const GLfloat *v) \
x(void, glWindowPos4iMESA, PFNGLWINDOWPOS4IMESAPROC, GLint x, GLint y, GLint z, GLint w) \
x(void, glWindowPos4ivMESA, PFNGLWINDOWPOS4IVMESAPROC, const GLint *v) \
x(void, glWindowPos4sMESA, PFNGLWINDOWPOS4SMESAPROC, GLshort x, GLshort y, GLshort z, GLshort w) \
x(void, glWindowPos4svMESA, PFNGLWINDOWPOS4SVMESAPROC, const GLshort *v) \
x(void, glBeginConditionalRenderNVX, PFNGLBEGINCONDITIONALRENDERNVXPROC, GLuint id) \
x(void, glEndConditionalRenderNVX, PFNGLENDCONDITIONALRENDERNVXPROC, void) \
x(void, glUploadGpuMaskNVX, PFNGLUPLOADGPUMASKNVXPROC, GLbitfield mask) \
x(void, glMulticastViewportArrayvNVX, PFNGLMULTICASTVIEWPORTARRAYVNVXPROC, GLuint gpu, GLuint first, GLsizei count, const GLfloat *v) \
x(void, glMulticastViewportPositionWScaleNVX, PFNGLMULTICASTVIEWPORTPOSITIONWSCALENVXPROC, GLuint gpu, GLuint index, GLfloat xcoeff, GLfloat ycoeff) \
x(void, glMulticastScissorArrayvNVX, PFNGLMULTICASTSCISSORARRAYVNVXPROC, GLuint gpu, GLuint first, GLsizei count, const GLint *v) \
x(GLuint, glAsyncCopyBufferSubDataNVX, PFNGLASYNCCOPYBUFFERSUBDATANVXPROC, GLsizei waitSemaphoreCount, const GLuint *waitSemaphoreArray, const GLuint64 *fenceValueArray, GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsizei signalSemaphoreCount, const GLuint *signalSemaphoreArray, const GLuint64 *signalValueArray) \
x(GLuint, glAsyncCopyImageSubDataNVX, PFNGLASYNCCOPYIMAGESUBDATANVXPROC, GLsizei waitSemaphoreCount, const GLuint *waitSemaphoreArray, const GLuint64 *waitValueArray, GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, GLsizei signalSemaphoreCount, const GLuint *signalSemaphoreArray, const GLuint64 *signalValueArray) \
x(void, glLGPUNamedBufferSubDataNVX, PFNGLLGPUNAMEDBUFFERSUBDATANVXPROC, GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) \
x(void, glLGPUCopyImageSubDataNVX, PFNGLLGPUCOPYIMAGESUBDATANVXPROC, GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srxY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) \
x(void, glLGPUInterlockNVX, PFNGLLGPUINTERLOCKNVXPROC, void) \
x(GLuint, glCreateProgressFenceNVX, PFNGLCREATEPROGRESSFENCENVXPROC, void) \
x(void, glSignalSemaphoreui64NVX, PFNGLSIGNALSEMAPHOREUI64NVXPROC, GLuint signalGpu, GLsizei fenceObjectCount, const GLuint *semaphoreArray, const GLuint64 *fenceValueArray) \
x(void, glWaitSemaphoreui64NVX, PFNGLWAITSEMAPHOREUI64NVXPROC, GLuint waitGpu, GLsizei fenceObjectCount, const GLuint *semaphoreArray, const GLuint64 *fenceValueArray) \
x(void, glClientWaitSemaphoreui64NVX, PFNGLCLIENTWAITSEMAPHOREUI64NVXPROC, GLsizei fenceObjectCount, const GLuint *semaphoreArray, const GLuint64 *fenceValueArray) \
x(void, glAlphaToCoverageDitherControlNV, PFNGLALPHATOCOVERAGEDITHERCONTROLNVPROC, GLenum mode) \
x(void, glMultiDrawArraysIndirectBindlessNV, PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC, GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount) \
x(void, glMultiDrawElementsIndirectBindlessNV, PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC, GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount) \
x(void, glMultiDrawArraysIndirectBindlessCountNV, PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC, GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount) \
x(void, glMultiDrawElementsIndirectBindlessCountNV, PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC, GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount) \
x(GLuint64, glGetTextureHandleNV, PFNGLGETTEXTUREHANDLENVPROC, GLuint texture) \
x(GLuint64, glGetTextureSamplerHandleNV, PFNGLGETTEXTURESAMPLERHANDLENVPROC, GLuint texture, GLuint sampler) \
x(void, glMakeTextureHandleResidentNV, PFNGLMAKETEXTUREHANDLERESIDENTNVPROC, GLuint64 handle) \
x(void, glMakeTextureHandleNonResidentNV, PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC, GLuint64 handle) \
x(GLuint64, glGetImageHandleNV, PFNGLGETIMAGEHANDLENVPROC, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) \
x(void, glMakeImageHandleResidentNV, PFNGLMAKEIMAGEHANDLERESIDENTNVPROC, GLuint64 handle, GLenum access) \
x(void, glMakeImageHandleNonResidentNV, PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC, GLuint64 handle) \
x(void, glUniformHandleui64NV, PFNGLUNIFORMHANDLEUI64NVPROC, GLint location, GLuint64 value) \
x(void, glUniformHandleui64vNV, PFNGLUNIFORMHANDLEUI64VNVPROC, GLint location, GLsizei count, const GLuint64 *value) \
x(void, glProgramUniformHandleui64NV, PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC, GLuint program, GLint location, GLuint64 value) \
x(void, glProgramUniformHandleui64vNV, PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC, GLuint program, GLint location, GLsizei count, const GLuint64 *values) \
x(GLboolean, glIsTextureHandleResidentNV, PFNGLISTEXTUREHANDLERESIDENTNVPROC, GLuint64 handle) \
x(GLboolean, glIsImageHandleResidentNV, PFNGLISIMAGEHANDLERESIDENTNVPROC, GLuint64 handle) \
x(void, glBlendParameteriNV, PFNGLBLENDPARAMETERINVPROC, GLenum pname, GLint value) \
x(void, glBlendBarrierNV, PFNGLBLENDBARRIERNVPROC, void) \
x(void, glViewportPositionWScaleNV, PFNGLVIEWPORTPOSITIONWSCALENVPROC, GLuint index, GLfloat xcoeff, GLfloat ycoeff) \
x(void, glCreateStatesNV, PFNGLCREATESTATESNVPROC, GLsizei n, GLuint *states) \
x(void, glDeleteStatesNV, PFNGLDELETESTATESNVPROC, GLsizei n, const GLuint *states) \
x(GLboolean, glIsStateNV, PFNGLISSTATENVPROC, GLuint state) \
x(void, glStateCaptureNV, PFNGLSTATECAPTURENVPROC, GLuint state, GLenum mode) \
x(GLuint, glGetCommandHeaderNV, PFNGLGETCOMMANDHEADERNVPROC, GLenum tokenID, GLuint size) \
x(GLushort, glGetStageIndexNV, PFNGLGETSTAGEINDEXNVPROC, GLenum shadertype) \
x(void, glDrawCommandsNV, PFNGLDRAWCOMMANDSNVPROC, GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count) \
x(void, glDrawCommandsAddressNV, PFNGLDRAWCOMMANDSADDRESSNVPROC, GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count) \
x(void, glDrawCommandsStatesNV, PFNGLDRAWCOMMANDSSTATESNVPROC, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count) \
x(void, glDrawCommandsStatesAddressNV, PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC, const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count) \
x(void, glCreateCommandListsNV, PFNGLCREATECOMMANDLISTSNVPROC, GLsizei n, GLuint *lists) \
x(void, glDeleteCommandListsNV, PFNGLDELETECOMMANDLISTSNVPROC, GLsizei n, const GLuint *lists) \
x(GLboolean, glIsCommandListNV, PFNGLISCOMMANDLISTNVPROC, GLuint list) \
x(void, glListDrawCommandsStatesClientNV, PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC, GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count) \
x(void, glCommandListSegmentsNV, PFNGLCOMMANDLISTSEGMENTSNVPROC, GLuint list, GLuint segments) \
x(void, glCompileCommandListNV, PFNGLCOMPILECOMMANDLISTNVPROC, GLuint list) \
x(void, glCallCommandListNV, PFNGLCALLCOMMANDLISTNVPROC, GLuint list) \
x(void, glBeginConditionalRenderNV, PFNGLBEGINCONDITIONALRENDERNVPROC, GLuint id, GLenum mode) \
x(void, glEndConditionalRenderNV, PFNGLENDCONDITIONALRENDERNVPROC, void) \
x(void, glSubpixelPrecisionBiasNV, PFNGLSUBPIXELPRECISIONBIASNVPROC, GLuint xbits, GLuint ybits) \
x(void, glConservativeRasterParameterfNV, PFNGLCONSERVATIVERASTERPARAMETERFNVPROC, GLenum pname, GLfloat value) \
x(void, glConservativeRasterParameteriNV, PFNGLCONSERVATIVERASTERPARAMETERINVPROC, GLenum pname, GLint param) \
x(void, glCopyImageSubDataNV, PFNGLCOPYIMAGESUBDATANVPROC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) \
x(void, glDepthRangedNV, PFNGLDEPTHRANGEDNVPROC, GLdouble zNear, GLdouble zFar) \
x(void, glClearDepthdNV, PFNGLCLEARDEPTHDNVPROC, GLdouble depth) \
x(void, glDepthBoundsdNV, PFNGLDEPTHBOUNDSDNVPROC, GLdouble zmin, GLdouble zmax) \
x(void, glDrawTextureNV, PFNGLDRAWTEXTURENVPROC, GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1) \
x(void, glDrawVkImageNV, PFNGLDRAWVKIMAGENVPROC, GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1) \
x(GLVULKANPROCNV, glGetVkProcAddrNV, PFNGLGETVKPROCADDRNVPROC, const GLchar *name) \
x(void, glWaitVkSemaphoreNV, PFNGLWAITVKSEMAPHORENVPROC, GLuint64 vkSemaphore) \
x(void, glSignalVkSemaphoreNV, PFNGLSIGNALVKSEMAPHORENVPROC, GLuint64 vkSemaphore) \
x(void, glSignalVkFenceNV, PFNGLSIGNALVKFENCENVPROC, GLuint64 vkFence) \
x(void, glMapControlPointsNV, PFNGLMAPCONTROLPOINTSNVPROC, GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void *points) \
x(void, glMapParameterivNV, PFNGLMAPPARAMETERIVNVPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glMapParameterfvNV, PFNGLMAPPARAMETERFVNVPROC, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glGetMapControlPointsNV, PFNGLGETMAPCONTROLPOINTSNVPROC, GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void *points) \
x(void, glGetMapParameterivNV, PFNGLGETMAPPARAMETERIVNVPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glGetMapParameterfvNV, PFNGLGETMAPPARAMETERFVNVPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetMapAttribParameterivNV, PFNGLGETMAPATTRIBPARAMETERIVNVPROC, GLenum target, GLuint index, GLenum pname, GLint *params) \
x(void, glGetMapAttribParameterfvNV, PFNGLGETMAPATTRIBPARAMETERFVNVPROC, GLenum target, GLuint index, GLenum pname, GLfloat *params) \
x(void, glEvalMapsNV, PFNGLEVALMAPSNVPROC, GLenum target, GLenum mode) \
x(void, glGetMultisamplefvNV, PFNGLGETMULTISAMPLEFVNVPROC, GLenum pname, GLuint index, GLfloat *val) \
x(void, glSampleMaskIndexedNV, PFNGLSAMPLEMASKINDEXEDNVPROC, GLuint index, GLbitfield mask) \
x(void, glTexRenderbufferNV, PFNGLTEXRENDERBUFFERNVPROC, GLenum target, GLuint renderbuffer) \
x(void, glDeleteFencesNV, PFNGLDELETEFENCESNVPROC, GLsizei n, const GLuint *fences) \
x(void, glGenFencesNV, PFNGLGENFENCESNVPROC, GLsizei n, GLuint *fences) \
x(GLboolean, glIsFenceNV, PFNGLISFENCENVPROC, GLuint fence) \
x(GLboolean, glTestFenceNV, PFNGLTESTFENCENVPROC, GLuint fence) \
x(void, glGetFenceivNV, PFNGLGETFENCEIVNVPROC, GLuint fence, GLenum pname, GLint *params) \
x(void, glFinishFenceNV, PFNGLFINISHFENCENVPROC, GLuint fence) \
x(void, glSetFenceNV, PFNGLSETFENCENVPROC, GLuint fence, GLenum condition) \
x(void, glFragmentCoverageColorNV, PFNGLFRAGMENTCOVERAGECOLORNVPROC, GLuint color) \
x(void, glProgramNamedParameter4fNV, PFNGLPROGRAMNAMEDPARAMETER4FNVPROC, GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glProgramNamedParameter4fvNV, PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC, GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v) \
x(void, glProgramNamedParameter4dNV, PFNGLPROGRAMNAMEDPARAMETER4DNVPROC, GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glProgramNamedParameter4dvNV, PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC, GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v) \
x(void, glGetProgramNamedParameterfvNV, PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC, GLuint id, GLsizei len, const GLubyte *name, GLfloat *params) \
x(void, glGetProgramNamedParameterdvNV, PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC, GLuint id, GLsizei len, const GLubyte *name, GLdouble *params) \
x(void, glCoverageModulationTableNV, PFNGLCOVERAGEMODULATIONTABLENVPROC, GLsizei n, const GLfloat *v) \
x(void, glGetCoverageModulationTableNV, PFNGLGETCOVERAGEMODULATIONTABLENVPROC, GLsizei bufSize, GLfloat *v) \
x(void, glCoverageModulationNV, PFNGLCOVERAGEMODULATIONNVPROC, GLenum components) \
x(void, glRenderbufferStorageMultisampleCoverageNV, PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) \
x(void, glProgramVertexLimitNV, PFNGLPROGRAMVERTEXLIMITNVPROC, GLenum target, GLint limit) \
x(void, glFramebufferTextureEXT, PFNGLFRAMEBUFFERTEXTUREEXTPROC, GLenum target, GLenum attachment, GLuint texture, GLint level) \
x(void, glFramebufferTextureFaceEXT, PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) \
x(void, glRenderGpuMaskNV, PFNGLRENDERGPUMASKNVPROC, GLbitfield mask) \
x(void, glMulticastBufferSubDataNV, PFNGLMULTICASTBUFFERSUBDATANVPROC, GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data) \
x(void, glMulticastCopyBufferSubDataNV, PFNGLMULTICASTCOPYBUFFERSUBDATANVPROC, GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) \
x(void, glMulticastCopyImageSubDataNV, PFNGLMULTICASTCOPYIMAGESUBDATANVPROC, GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) \
x(void, glMulticastBlitFramebufferNV, PFNGLMULTICASTBLITFRAMEBUFFERNVPROC, GLuint srcGpu, GLuint dstGpu, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) \
x(void, glMulticastFramebufferSampleLocationsfvNV, PFNGLMULTICASTFRAMEBUFFERSAMPLELOCATIONSFVNVPROC, GLuint gpu, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v) \
x(void, glMulticastBarrierNV, PFNGLMULTICASTBARRIERNVPROC, void) \
x(void, glMulticastWaitSyncNV, PFNGLMULTICASTWAITSYNCNVPROC, GLuint signalGpu, GLbitfield waitGpuMask) \
x(void, glMulticastGetQueryObjectivNV, PFNGLMULTICASTGETQUERYOBJECTIVNVPROC, GLuint gpu, GLuint id, GLenum pname, GLint *params) \
x(void, glMulticastGetQueryObjectuivNV, PFNGLMULTICASTGETQUERYOBJECTUIVNVPROC, GLuint gpu, GLuint id, GLenum pname, GLuint *params) \
x(void, glMulticastGetQueryObjecti64vNV, PFNGLMULTICASTGETQUERYOBJECTI64VNVPROC, GLuint gpu, GLuint id, GLenum pname, GLint64 *params) \
x(void, glMulticastGetQueryObjectui64vNV, PFNGLMULTICASTGETQUERYOBJECTUI64VNVPROC, GLuint gpu, GLuint id, GLenum pname, GLuint64 *params) \
x(void, glProgramLocalParameterI4iNV, PFNGLPROGRAMLOCALPARAMETERI4INVPROC, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) \
x(void, glProgramLocalParameterI4ivNV, PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC, GLenum target, GLuint index, const GLint *params) \
x(void, glProgramLocalParametersI4ivNV, PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC, GLenum target, GLuint index, GLsizei count, const GLint *params) \
x(void, glProgramLocalParameterI4uiNV, PFNGLPROGRAMLOCALPARAMETERI4UINVPROC, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) \
x(void, glProgramLocalParameterI4uivNV, PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC, GLenum target, GLuint index, const GLuint *params) \
x(void, glProgramLocalParametersI4uivNV, PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC, GLenum target, GLuint index, GLsizei count, const GLuint *params) \
x(void, glProgramEnvParameterI4iNV, PFNGLPROGRAMENVPARAMETERI4INVPROC, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) \
x(void, glProgramEnvParameterI4ivNV, PFNGLPROGRAMENVPARAMETERI4IVNVPROC, GLenum target, GLuint index, const GLint *params) \
x(void, glProgramEnvParametersI4ivNV, PFNGLPROGRAMENVPARAMETERSI4IVNVPROC, GLenum target, GLuint index, GLsizei count, const GLint *params) \
x(void, glProgramEnvParameterI4uiNV, PFNGLPROGRAMENVPARAMETERI4UINVPROC, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) \
x(void, glProgramEnvParameterI4uivNV, PFNGLPROGRAMENVPARAMETERI4UIVNVPROC, GLenum target, GLuint index, const GLuint *params) \
x(void, glProgramEnvParametersI4uivNV, PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC, GLenum target, GLuint index, GLsizei count, const GLuint *params) \
x(void, glGetProgramLocalParameterIivNV, PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC, GLenum target, GLuint index, GLint *params) \
x(void, glGetProgramLocalParameterIuivNV, PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC, GLenum target, GLuint index, GLuint *params) \
x(void, glGetProgramEnvParameterIivNV, PFNGLGETPROGRAMENVPARAMETERIIVNVPROC, GLenum target, GLuint index, GLint *params) \
x(void, glGetProgramEnvParameterIuivNV, PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC, GLenum target, GLuint index, GLuint *params) \
x(void, glProgramSubroutineParametersuivNV, PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC, GLenum target, GLsizei count, const GLuint *params) \
x(void, glGetProgramSubroutineParameteruivNV, PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC, GLenum target, GLuint index, GLuint *param) \
x(void, glVertex2hNV, PFNGLVERTEX2HNVPROC, GLhalfNV x, GLhalfNV y) \
x(void, glVertex2hvNV, PFNGLVERTEX2HVNVPROC, const GLhalfNV *v) \
x(void, glVertex3hNV, PFNGLVERTEX3HNVPROC, GLhalfNV x, GLhalfNV y, GLhalfNV z) \
x(void, glVertex3hvNV, PFNGLVERTEX3HVNVPROC, const GLhalfNV *v) \
x(void, glVertex4hNV, PFNGLVERTEX4HNVPROC, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) \
x(void, glVertex4hvNV, PFNGLVERTEX4HVNVPROC, const GLhalfNV *v) \
x(void, glNormal3hNV, PFNGLNORMAL3HNVPROC, GLhalfNV nx, GLhalfNV ny, GLhalfNV nz) \
x(void, glNormal3hvNV, PFNGLNORMAL3HVNVPROC, const GLhalfNV *v) \
x(void, glColor3hNV, PFNGLCOLOR3HNVPROC, GLhalfNV red, GLhalfNV green, GLhalfNV blue) \
x(void, glColor3hvNV, PFNGLCOLOR3HVNVPROC, const GLhalfNV *v) \
x(void, glColor4hNV, PFNGLCOLOR4HNVPROC, GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha) \
x(void, glColor4hvNV, PFNGLCOLOR4HVNVPROC, const GLhalfNV *v) \
x(void, glTexCoord1hNV, PFNGLTEXCOORD1HNVPROC, GLhalfNV s) \
x(void, glTexCoord1hvNV, PFNGLTEXCOORD1HVNVPROC, const GLhalfNV *v) \
x(void, glTexCoord2hNV, PFNGLTEXCOORD2HNVPROC, GLhalfNV s, GLhalfNV t) \
x(void, glTexCoord2hvNV, PFNGLTEXCOORD2HVNVPROC, const GLhalfNV *v) \
x(void, glTexCoord3hNV, PFNGLTEXCOORD3HNVPROC, GLhalfNV s, GLhalfNV t, GLhalfNV r) \
x(void, glTexCoord3hvNV, PFNGLTEXCOORD3HVNVPROC, const GLhalfNV *v) \
x(void, glTexCoord4hNV, PFNGLTEXCOORD4HNVPROC, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) \
x(void, glTexCoord4hvNV, PFNGLTEXCOORD4HVNVPROC, const GLhalfNV *v) \
x(void, glMultiTexCoord1hNV, PFNGLMULTITEXCOORD1HNVPROC, GLenum target, GLhalfNV s) \
x(void, glMultiTexCoord1hvNV, PFNGLMULTITEXCOORD1HVNVPROC, GLenum target, const GLhalfNV *v) \
x(void, glMultiTexCoord2hNV, PFNGLMULTITEXCOORD2HNVPROC, GLenum target, GLhalfNV s, GLhalfNV t) \
x(void, glMultiTexCoord2hvNV, PFNGLMULTITEXCOORD2HVNVPROC, GLenum target, const GLhalfNV *v) \
x(void, glMultiTexCoord3hNV, PFNGLMULTITEXCOORD3HNVPROC, GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r) \
x(void, glMultiTexCoord3hvNV, PFNGLMULTITEXCOORD3HVNVPROC, GLenum target, const GLhalfNV *v) \
x(void, glMultiTexCoord4hNV, PFNGLMULTITEXCOORD4HNVPROC, GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) \
x(void, glMultiTexCoord4hvNV, PFNGLMULTITEXCOORD4HVNVPROC, GLenum target, const GLhalfNV *v) \
x(void, glFogCoordhNV, PFNGLFOGCOORDHNVPROC, GLhalfNV fog) \
x(void, glFogCoordhvNV, PFNGLFOGCOORDHVNVPROC, const GLhalfNV *fog) \
x(void, glSecondaryColor3hNV, PFNGLSECONDARYCOLOR3HNVPROC, GLhalfNV red, GLhalfNV green, GLhalfNV blue) \
x(void, glSecondaryColor3hvNV, PFNGLSECONDARYCOLOR3HVNVPROC, const GLhalfNV *v) \
x(void, glVertexWeighthNV, PFNGLVERTEXWEIGHTHNVPROC, GLhalfNV weight) \
x(void, glVertexWeighthvNV, PFNGLVERTEXWEIGHTHVNVPROC, const GLhalfNV *weight) \
x(void, glVertexAttrib1hNV, PFNGLVERTEXATTRIB1HNVPROC, GLuint index, GLhalfNV x) \
x(void, glVertexAttrib1hvNV, PFNGLVERTEXATTRIB1HVNVPROC, GLuint index, const GLhalfNV *v) \
x(void, glVertexAttrib2hNV, PFNGLVERTEXATTRIB2HNVPROC, GLuint index, GLhalfNV x, GLhalfNV y) \
x(void, glVertexAttrib2hvNV, PFNGLVERTEXATTRIB2HVNVPROC, GLuint index, const GLhalfNV *v) \
x(void, glVertexAttrib3hNV, PFNGLVERTEXATTRIB3HNVPROC, GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z) \
x(void, glVertexAttrib3hvNV, PFNGLVERTEXATTRIB3HVNVPROC, GLuint index, const GLhalfNV *v) \
x(void, glVertexAttrib4hNV, PFNGLVERTEXATTRIB4HNVPROC, GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) \
x(void, glVertexAttrib4hvNV, PFNGLVERTEXATTRIB4HVNVPROC, GLuint index, const GLhalfNV *v) \
x(void, glVertexAttribs1hvNV, PFNGLVERTEXATTRIBS1HVNVPROC, GLuint index, GLsizei n, const GLhalfNV *v) \
x(void, glVertexAttribs2hvNV, PFNGLVERTEXATTRIBS2HVNVPROC, GLuint index, GLsizei n, const GLhalfNV *v) \
x(void, glVertexAttribs3hvNV, PFNGLVERTEXATTRIBS3HVNVPROC, GLuint index, GLsizei n, const GLhalfNV *v) \
x(void, glVertexAttribs4hvNV, PFNGLVERTEXATTRIBS4HVNVPROC, GLuint index, GLsizei n, const GLhalfNV *v) \
x(void, glGetInternalformatSampleivNV, PFNGLGETINTERNALFORMATSAMPLEIVNVPROC, GLenum target, GLenum internalformat, GLsizei samples, GLenum pname, GLsizei count, GLint *params) \
x(void, glGetMemoryObjectDetachedResourcesuivNV, PFNGLGETMEMORYOBJECTDETACHEDRESOURCESUIVNVPROC, GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint *params) \
x(void, glResetMemoryObjectParameterNV, PFNGLRESETMEMORYOBJECTPARAMETERNVPROC, GLuint memory, GLenum pname) \
x(void, glTexAttachMemoryNV, PFNGLTEXATTACHMEMORYNVPROC, GLenum target, GLuint memory, GLuint64 offset) \
x(void, glBufferAttachMemoryNV, PFNGLBUFFERATTACHMEMORYNVPROC, GLenum target, GLuint memory, GLuint64 offset) \
x(void, glTextureAttachMemoryNV, PFNGLTEXTUREATTACHMEMORYNVPROC, GLuint texture, GLuint memory, GLuint64 offset) \
x(void, glNamedBufferAttachMemoryNV, PFNGLNAMEDBUFFERATTACHMEMORYNVPROC, GLuint buffer, GLuint memory, GLuint64 offset) \
x(void, glBufferPageCommitmentMemNV, PFNGLBUFFERPAGECOMMITMENTMEMNVPROC, GLenum target, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit) \
x(void, glTexPageCommitmentMemNV, PFNGLTEXPAGECOMMITMENTMEMNVPROC, GLenum target, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit) \
x(void, glNamedBufferPageCommitmentMemNV, PFNGLNAMEDBUFFERPAGECOMMITMENTMEMNVPROC, GLuint buffer, GLintptr offset, GLsizeiptr size, GLuint memory, GLuint64 memOffset, GLboolean commit) \
x(void, glTexturePageCommitmentMemNV, PFNGLTEXTUREPAGECOMMITMENTMEMNVPROC, GLuint texture, GLint layer, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset, GLboolean commit) \
x(void, glDrawMeshTasksNV, PFNGLDRAWMESHTASKSNVPROC, GLuint first, GLuint count) \
x(void, glDrawMeshTasksIndirectNV, PFNGLDRAWMESHTASKSINDIRECTNVPROC, GLintptr indirect) \
x(void, glMultiDrawMeshTasksIndirectNV, PFNGLMULTIDRAWMESHTASKSINDIRECTNVPROC, GLintptr indirect, GLsizei drawcount, GLsizei stride) \
x(void, glMultiDrawMeshTasksIndirectCountNV, PFNGLMULTIDRAWMESHTASKSINDIRECTCOUNTNVPROC, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride) \
x(void, glGenOcclusionQueriesNV, PFNGLGENOCCLUSIONQUERIESNVPROC, GLsizei n, GLuint *ids) \
x(void, glDeleteOcclusionQueriesNV, PFNGLDELETEOCCLUSIONQUERIESNVPROC, GLsizei n, const GLuint *ids) \
x(GLboolean, glIsOcclusionQueryNV, PFNGLISOCCLUSIONQUERYNVPROC, GLuint id) \
x(void, glBeginOcclusionQueryNV, PFNGLBEGINOCCLUSIONQUERYNVPROC, GLuint id) \
x(void, glEndOcclusionQueryNV, PFNGLENDOCCLUSIONQUERYNVPROC, void) \
x(void, glGetOcclusionQueryivNV, PFNGLGETOCCLUSIONQUERYIVNVPROC, GLuint id, GLenum pname, GLint *params) \
x(void, glGetOcclusionQueryuivNV, PFNGLGETOCCLUSIONQUERYUIVNVPROC, GLuint id, GLenum pname, GLuint *params) \
x(void, glProgramBufferParametersfvNV, PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat *params) \
x(void, glProgramBufferParametersIivNV, PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint *params) \
x(void, glProgramBufferParametersIuivNV, PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint *params) \
x(GLuint, glGenPathsNV, PFNGLGENPATHSNVPROC, GLsizei range) \
x(void, glDeletePathsNV, PFNGLDELETEPATHSNVPROC, GLuint path, GLsizei range) \
x(GLboolean, glIsPathNV, PFNGLISPATHNVPROC, GLuint path) \
x(void, glPathCommandsNV, PFNGLPATHCOMMANDSNVPROC, GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords) \
x(void, glPathCoordsNV, PFNGLPATHCOORDSNVPROC, GLuint path, GLsizei numCoords, GLenum coordType, const void *coords) \
x(void, glPathSubCommandsNV, PFNGLPATHSUBCOMMANDSNVPROC, GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords) \
x(void, glPathSubCoordsNV, PFNGLPATHSUBCOORDSNVPROC, GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords) \
x(void, glPathStringNV, PFNGLPATHSTRINGNVPROC, GLuint path, GLenum format, GLsizei length, const void *pathString) \
x(void, glPathGlyphsNV, PFNGLPATHGLYPHSNVPROC, GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) \
x(void, glPathGlyphRangeNV, PFNGLPATHGLYPHRANGENVPROC, GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) \
x(void, glWeightPathsNV, PFNGLWEIGHTPATHSNVPROC, GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights) \
x(void, glCopyPathNV, PFNGLCOPYPATHNVPROC, GLuint resultPath, GLuint srcPath) \
x(void, glInterpolatePathsNV, PFNGLINTERPOLATEPATHSNVPROC, GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight) \
x(void, glTransformPathNV, PFNGLTRANSFORMPATHNVPROC, GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues) \
x(void, glPathParameterivNV, PFNGLPATHPARAMETERIVNVPROC, GLuint path, GLenum pname, const GLint *value) \
x(void, glPathParameteriNV, PFNGLPATHPARAMETERINVPROC, GLuint path, GLenum pname, GLint value) \
x(void, glPathParameterfvNV, PFNGLPATHPARAMETERFVNVPROC, GLuint path, GLenum pname, const GLfloat *value) \
x(void, glPathParameterfNV, PFNGLPATHPARAMETERFNVPROC, GLuint path, GLenum pname, GLfloat value) \
x(void, glPathDashArrayNV, PFNGLPATHDASHARRAYNVPROC, GLuint path, GLsizei dashCount, const GLfloat *dashArray) \
x(void, glPathStencilFuncNV, PFNGLPATHSTENCILFUNCNVPROC, GLenum func, GLint ref, GLuint mask) \
x(void, glPathStencilDepthOffsetNV, PFNGLPATHSTENCILDEPTHOFFSETNVPROC, GLfloat factor, GLfloat units) \
x(void, glStencilFillPathNV, PFNGLSTENCILFILLPATHNVPROC, GLuint path, GLenum fillMode, GLuint mask) \
x(void, glStencilStrokePathNV, PFNGLSTENCILSTROKEPATHNVPROC, GLuint path, GLint reference, GLuint mask) \
x(void, glStencilFillPathInstancedNV, PFNGLSTENCILFILLPATHINSTANCEDNVPROC, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues) \
x(void, glStencilStrokePathInstancedNV, PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues) \
x(void, glPathCoverDepthFuncNV, PFNGLPATHCOVERDEPTHFUNCNVPROC, GLenum func) \
x(void, glCoverFillPathNV, PFNGLCOVERFILLPATHNVPROC, GLuint path, GLenum coverMode) \
x(void, glCoverStrokePathNV, PFNGLCOVERSTROKEPATHNVPROC, GLuint path, GLenum coverMode) \
x(void, glCoverFillPathInstancedNV, PFNGLCOVERFILLPATHINSTANCEDNVPROC, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues) \
x(void, glCoverStrokePathInstancedNV, PFNGLCOVERSTROKEPATHINSTANCEDNVPROC, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues) \
x(void, glGetPathParameterivNV, PFNGLGETPATHPARAMETERIVNVPROC, GLuint path, GLenum pname, GLint *value) \
x(void, glGetPathParameterfvNV, PFNGLGETPATHPARAMETERFVNVPROC, GLuint path, GLenum pname, GLfloat *value) \
x(void, glGetPathCommandsNV, PFNGLGETPATHCOMMANDSNVPROC, GLuint path, GLubyte *commands) \
x(void, glGetPathCoordsNV, PFNGLGETPATHCOORDSNVPROC, GLuint path, GLfloat *coords) \
x(void, glGetPathDashArrayNV, PFNGLGETPATHDASHARRAYNVPROC, GLuint path, GLfloat *dashArray) \
x(void, glGetPathMetricsNV, PFNGLGETPATHMETRICSNVPROC, GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics) \
x(void, glGetPathMetricRangeNV, PFNGLGETPATHMETRICRANGENVPROC, GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics) \
x(void, glGetPathSpacingNV, PFNGLGETPATHSPACINGNVPROC, GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing) \
x(GLboolean, glIsPointInFillPathNV, PFNGLISPOINTINFILLPATHNVPROC, GLuint path, GLuint mask, GLfloat x, GLfloat y) \
x(GLboolean, glIsPointInStrokePathNV, PFNGLISPOINTINSTROKEPATHNVPROC, GLuint path, GLfloat x, GLfloat y) \
x(GLfloat, glGetPathLengthNV, PFNGLGETPATHLENGTHNVPROC, GLuint path, GLsizei startSegment, GLsizei numSegments) \
x(GLboolean, glPointAlongPathNV, PFNGLPOINTALONGPATHNVPROC, GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY) \
x(void, glMatrixLoad3x2fNV, PFNGLMATRIXLOAD3X2FNVPROC, GLenum matrixMode, const GLfloat *m) \
x(void, glMatrixLoad3x3fNV, PFNGLMATRIXLOAD3X3FNVPROC, GLenum matrixMode, const GLfloat *m) \
x(void, glMatrixLoadTranspose3x3fNV, PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC, GLenum matrixMode, const GLfloat *m) \
x(void, glMatrixMult3x2fNV, PFNGLMATRIXMULT3X2FNVPROC, GLenum matrixMode, const GLfloat *m) \
x(void, glMatrixMult3x3fNV, PFNGLMATRIXMULT3X3FNVPROC, GLenum matrixMode, const GLfloat *m) \
x(void, glMatrixMultTranspose3x3fNV, PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC, GLenum matrixMode, const GLfloat *m) \
x(void, glStencilThenCoverFillPathNV, PFNGLSTENCILTHENCOVERFILLPATHNVPROC, GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode) \
x(void, glStencilThenCoverStrokePathNV, PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC, GLuint path, GLint reference, GLuint mask, GLenum coverMode) \
x(void, glStencilThenCoverFillPathInstancedNV, PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues) \
x(void, glStencilThenCoverStrokePathInstancedNV, PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues) \
x(GLenum, glPathGlyphIndexRangeNV, PFNGLPATHGLYPHINDEXRANGENVPROC, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint *baseAndCount) \
x(GLenum, glPathGlyphIndexArrayNV, PFNGLPATHGLYPHINDEXARRAYNVPROC, GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale) \
x(GLenum, glPathMemoryGlyphIndexArrayNV, PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC, GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale) \
x(void, glProgramPathFragmentInputGenNV, PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC, GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs) \
x(void, glGetProgramResourcefvNV, PFNGLGETPROGRAMRESOURCEFVNVPROC, GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei count, GLsizei *length, GLfloat *params) \
x(void, glPathColorGenNV, PFNGLPATHCOLORGENNVPROC, GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat *coeffs) \
x(void, glPathTexGenNV, PFNGLPATHTEXGENNVPROC, GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat *coeffs) \
x(void, glPathFogGenNV, PFNGLPATHFOGGENNVPROC, GLenum genMode) \
x(void, glGetPathColorGenivNV, PFNGLGETPATHCOLORGENIVNVPROC, GLenum color, GLenum pname, GLint *value) \
x(void, glGetPathColorGenfvNV, PFNGLGETPATHCOLORGENFVNVPROC, GLenum color, GLenum pname, GLfloat *value) \
x(void, glGetPathTexGenivNV, PFNGLGETPATHTEXGENIVNVPROC, GLenum texCoordSet, GLenum pname, GLint *value) \
x(void, glGetPathTexGenfvNV, PFNGLGETPATHTEXGENFVNVPROC, GLenum texCoordSet, GLenum pname, GLfloat *value) \
x(void, glPixelDataRangeNV, PFNGLPIXELDATARANGENVPROC, GLenum target, GLsizei length, const void *pointer) \
x(void, glFlushPixelDataRangeNV, PFNGLFLUSHPIXELDATARANGENVPROC, GLenum target) \
x(void, glPointParameteriNV, PFNGLPOINTPARAMETERINVPROC, GLenum pname, GLint param) \
x(void, glPointParameterivNV, PFNGLPOINTPARAMETERIVNVPROC, GLenum pname, const GLint *params) \
x(void, glPresentFrameKeyedNV, PFNGLPRESENTFRAMEKEYEDNVPROC, GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1) \
x(void, glPresentFrameDualFillNV, PFNGLPRESENTFRAMEDUALFILLNVPROC, GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3) \
x(void, glGetVideoivNV, PFNGLGETVIDEOIVNVPROC, GLuint video_slot, GLenum pname, GLint *params) \
x(void, glGetVideouivNV, PFNGLGETVIDEOUIVNVPROC, GLuint video_slot, GLenum pname, GLuint *params) \
x(void, glGetVideoi64vNV, PFNGLGETVIDEOI64VNVPROC, GLuint video_slot, GLenum pname, GLint64EXT *params) \
x(void, glGetVideoui64vNV, PFNGLGETVIDEOUI64VNVPROC, GLuint video_slot, GLenum pname, GLuint64EXT *params) \
x(void, glPrimitiveRestartNV, PFNGLPRIMITIVERESTARTNVPROC, void) \
x(void, glPrimitiveRestartIndexNV, PFNGLPRIMITIVERESTARTINDEXNVPROC, GLuint index) \
x(GLint, glQueryResourceNV, PFNGLQUERYRESOURCENVPROC, GLenum queryType, GLint tagId, GLuint count, GLint *buffer) \
x(void, glGenQueryResourceTagNV, PFNGLGENQUERYRESOURCETAGNVPROC, GLsizei n, GLint *tagIds) \
x(void, glDeleteQueryResourceTagNV, PFNGLDELETEQUERYRESOURCETAGNVPROC, GLsizei n, const GLint *tagIds) \
x(void, glQueryResourceTagNV, PFNGLQUERYRESOURCETAGNVPROC, GLint tagId, const GLchar *tagString) \
x(void, glCombinerParameterfvNV, PFNGLCOMBINERPARAMETERFVNVPROC, GLenum pname, const GLfloat *params) \
x(void, glCombinerParameterfNV, PFNGLCOMBINERPARAMETERFNVPROC, GLenum pname, GLfloat param) \
x(void, glCombinerParameterivNV, PFNGLCOMBINERPARAMETERIVNVPROC, GLenum pname, const GLint *params) \
x(void, glCombinerParameteriNV, PFNGLCOMBINERPARAMETERINVPROC, GLenum pname, GLint param) \
x(void, glCombinerInputNV, PFNGLCOMBINERINPUTNVPROC, GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) \
x(void, glCombinerOutputNV, PFNGLCOMBINEROUTPUTNVPROC, GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum) \
x(void, glFinalCombinerInputNV, PFNGLFINALCOMBINERINPUTNVPROC, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) \
x(void, glGetCombinerInputParameterfvNV, PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params) \
x(void, glGetCombinerInputParameterivNV, PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params) \
x(void, glGetCombinerOutputParameterfvNV, PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC, GLenum stage, GLenum portion, GLenum pname, GLfloat *params) \
x(void, glGetCombinerOutputParameterivNV, PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC, GLenum stage, GLenum portion, GLenum pname, GLint *params) \
x(void, glGetFinalCombinerInputParameterfvNV, PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC, GLenum variable, GLenum pname, GLfloat *params) \
x(void, glGetFinalCombinerInputParameterivNV, PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC, GLenum variable, GLenum pname, GLint *params) \
x(void, glCombinerStageParameterfvNV, PFNGLCOMBINERSTAGEPARAMETERFVNVPROC, GLenum stage, GLenum pname, const GLfloat *params) \
x(void, glGetCombinerStageParameterfvNV, PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC, GLenum stage, GLenum pname, GLfloat *params) \
x(void, glFramebufferSampleLocationsfvNV, PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC, GLenum target, GLuint start, GLsizei count, const GLfloat *v) \
x(void, glNamedFramebufferSampleLocationsfvNV, PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v) \
x(void, glResolveDepthValuesNV, PFNGLRESOLVEDEPTHVALUESNVPROC, void) \
x(void, glScissorExclusiveNV, PFNGLSCISSOREXCLUSIVENVPROC, GLint x, GLint y, GLsizei width, GLsizei height) \
x(void, glScissorExclusiveArrayvNV, PFNGLSCISSOREXCLUSIVEARRAYVNVPROC, GLuint first, GLsizei count, const GLint *v) \
x(void, glMakeBufferResidentNV, PFNGLMAKEBUFFERRESIDENTNVPROC, GLenum target, GLenum access) \
x(void, glMakeBufferNonResidentNV, PFNGLMAKEBUFFERNONRESIDENTNVPROC, GLenum target) \
x(GLboolean, glIsBufferResidentNV, PFNGLISBUFFERRESIDENTNVPROC, GLenum target) \
x(void, glMakeNamedBufferResidentNV, PFNGLMAKENAMEDBUFFERRESIDENTNVPROC, GLuint buffer, GLenum access) \
x(void, glMakeNamedBufferNonResidentNV, PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC, GLuint buffer) \
x(GLboolean, glIsNamedBufferResidentNV, PFNGLISNAMEDBUFFERRESIDENTNVPROC, GLuint buffer) \
x(void, glGetBufferParameterui64vNV, PFNGLGETBUFFERPARAMETERUI64VNVPROC, GLenum target, GLenum pname, GLuint64EXT *params) \
x(void, glGetNamedBufferParameterui64vNV, PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC, GLuint buffer, GLenum pname, GLuint64EXT *params) \
x(void, glGetIntegerui64vNV, PFNGLGETINTEGERUI64VNVPROC, GLenum value, GLuint64EXT *result) \
x(void, glUniformui64NV, PFNGLUNIFORMUI64NVPROC, GLint location, GLuint64EXT value) \
x(void, glUniformui64vNV, PFNGLUNIFORMUI64VNVPROC, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glProgramUniformui64NV, PFNGLPROGRAMUNIFORMUI64NVPROC, GLuint program, GLint location, GLuint64EXT value) \
x(void, glProgramUniformui64vNV, PFNGLPROGRAMUNIFORMUI64VNVPROC, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value) \
x(void, glBindShadingRateImageNV, PFNGLBINDSHADINGRATEIMAGENVPROC, GLuint texture) \
x(void, glGetShadingRateImagePaletteNV, PFNGLGETSHADINGRATEIMAGEPALETTENVPROC, GLuint viewport, GLuint entry, GLenum *rate) \
x(void, glGetShadingRateSampleLocationivNV, PFNGLGETSHADINGRATESAMPLELOCATIONIVNVPROC, GLenum rate, GLuint samples, GLuint index, GLint *location) \
x(void, glShadingRateImageBarrierNV, PFNGLSHADINGRATEIMAGEBARRIERNVPROC, GLboolean synchronize) \
x(void, glShadingRateImagePaletteNV, PFNGLSHADINGRATEIMAGEPALETTENVPROC, GLuint viewport, GLuint first, GLsizei count, const GLenum *rates) \
x(void, glShadingRateSampleOrderNV, PFNGLSHADINGRATESAMPLEORDERNVPROC, GLenum order) \
x(void, glShadingRateSampleOrderCustomNV, PFNGLSHADINGRATESAMPLEORDERCUSTOMNVPROC, GLenum rate, GLuint samples, const GLint *locations) \
x(void, glTextureBarrierNV, PFNGLTEXTUREBARRIERNVPROC, void) \
x(void, glTexImage2DMultisampleCoverageNV, PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) \
x(void, glTexImage3DMultisampleCoverageNV, PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) \
x(void, glTextureImage2DMultisampleNV, PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC, GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) \
x(void, glTextureImage3DMultisampleNV, PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC, GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) \
x(void, glTextureImage2DMultisampleCoverageNV, PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC, GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) \
x(void, glTextureImage3DMultisampleCoverageNV, PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC, GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) \
x(void, glCreateSemaphoresNV, PFNGLCREATESEMAPHORESNVPROC, GLsizei n, GLuint *semaphores) \
x(void, glSemaphoreParameterivNV, PFNGLSEMAPHOREPARAMETERIVNVPROC, GLuint semaphore, GLenum pname, const GLint *params) \
x(void, glGetSemaphoreParameterivNV, PFNGLGETSEMAPHOREPARAMETERIVNVPROC, GLuint semaphore, GLenum pname, GLint *params) \
x(void, glBeginTransformFeedbackNV, PFNGLBEGINTRANSFORMFEEDBACKNVPROC, GLenum primitiveMode) \
x(void, glEndTransformFeedbackNV, PFNGLENDTRANSFORMFEEDBACKNVPROC, void) \
x(void, glTransformFeedbackAttribsNV, PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC, GLsizei count, const GLint *attribs, GLenum bufferMode) \
x(void, glBindBufferRangeNV, PFNGLBINDBUFFERRANGENVPROC, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) \
x(void, glBindBufferOffsetNV, PFNGLBINDBUFFEROFFSETNVPROC, GLenum target, GLuint index, GLuint buffer, GLintptr offset) \
x(void, glBindBufferBaseNV, PFNGLBINDBUFFERBASENVPROC, GLenum target, GLuint index, GLuint buffer) \
x(void, glTransformFeedbackVaryingsNV, PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC, GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode) \
x(void, glActiveVaryingNV, PFNGLACTIVEVARYINGNVPROC, GLuint program, const GLchar *name) \
x(GLint, glGetVaryingLocationNV, PFNGLGETVARYINGLOCATIONNVPROC, GLuint program, const GLchar *name) \
x(void, glGetActiveVaryingNV, PFNGLGETACTIVEVARYINGNVPROC, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name) \
x(void, glGetTransformFeedbackVaryingNV, PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC, GLuint program, GLuint index, GLint *location) \
x(void, glTransformFeedbackStreamAttribsNV, PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC, GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode) \
x(void, glBindTransformFeedbackNV, PFNGLBINDTRANSFORMFEEDBACKNVPROC, GLenum target, GLuint id) \
x(void, glDeleteTransformFeedbacksNV, PFNGLDELETETRANSFORMFEEDBACKSNVPROC, GLsizei n, const GLuint *ids) \
x(void, glGenTransformFeedbacksNV, PFNGLGENTRANSFORMFEEDBACKSNVPROC, GLsizei n, GLuint *ids) \
x(GLboolean, glIsTransformFeedbackNV, PFNGLISTRANSFORMFEEDBACKNVPROC, GLuint id) \
x(void, glPauseTransformFeedbackNV, PFNGLPAUSETRANSFORMFEEDBACKNVPROC, void) \
x(void, glResumeTransformFeedbackNV, PFNGLRESUMETRANSFORMFEEDBACKNVPROC, void) \
x(void, glDrawTransformFeedbackNV, PFNGLDRAWTRANSFORMFEEDBACKNVPROC, GLenum mode, GLuint id) \
x(void, glVDPAUInitNV, PFNGLVDPAUINITNVPROC, const void *vdpDevice, const void *getProcAddress) \
x(void, glVDPAUFiniNV, PFNGLVDPAUFININVPROC, void) \
x(GLvdpauSurfaceNV, glVDPAURegisterVideoSurfaceNV, PFNGLVDPAUREGISTERVIDEOSURFACENVPROC, const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames) \
x(GLvdpauSurfaceNV, glVDPAURegisterOutputSurfaceNV, PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC, const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames) \
x(GLboolean, glVDPAUIsSurfaceNV, PFNGLVDPAUISSURFACENVPROC, GLvdpauSurfaceNV surface) \
x(void, glVDPAUUnregisterSurfaceNV, PFNGLVDPAUUNREGISTERSURFACENVPROC, GLvdpauSurfaceNV surface) \
x(void, glVDPAUGetSurfaceivNV, PFNGLVDPAUGETSURFACEIVNVPROC, GLvdpauSurfaceNV surface, GLenum pname, GLsizei count, GLsizei *length, GLint *values) \
x(void, glVDPAUSurfaceAccessNV, PFNGLVDPAUSURFACEACCESSNVPROC, GLvdpauSurfaceNV surface, GLenum access) \
x(void, glVDPAUMapSurfacesNV, PFNGLVDPAUMAPSURFACESNVPROC, GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces) \
x(void, glVDPAUUnmapSurfacesNV, PFNGLVDPAUUNMAPSURFACESNVPROC, GLsizei numSurface, const GLvdpauSurfaceNV *surfaces) \
x(GLvdpauSurfaceNV, glVDPAURegisterVideoSurfaceWithPictureStructureNV, PFNGLVDPAUREGISTERVIDEOSURFACEWITHPICTURESTRUCTURENVPROC, const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames, GLboolean isFrameStructure) \
x(void, glFlushVertexArrayRangeNV, PFNGLFLUSHVERTEXARRAYRANGENVPROC, void) \
x(void, glVertexArrayRangeNV, PFNGLVERTEXARRAYRANGENVPROC, GLsizei length, const void *pointer) \
x(void, glVertexAttribL1i64NV, PFNGLVERTEXATTRIBL1I64NVPROC, GLuint index, GLint64EXT x) \
x(void, glVertexAttribL2i64NV, PFNGLVERTEXATTRIBL2I64NVPROC, GLuint index, GLint64EXT x, GLint64EXT y) \
x(void, glVertexAttribL3i64NV, PFNGLVERTEXATTRIBL3I64NVPROC, GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z) \
x(void, glVertexAttribL4i64NV, PFNGLVERTEXATTRIBL4I64NVPROC, GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) \
x(void, glVertexAttribL1i64vNV, PFNGLVERTEXATTRIBL1I64VNVPROC, GLuint index, const GLint64EXT *v) \
x(void, glVertexAttribL2i64vNV, PFNGLVERTEXATTRIBL2I64VNVPROC, GLuint index, const GLint64EXT *v) \
x(void, glVertexAttribL3i64vNV, PFNGLVERTEXATTRIBL3I64VNVPROC, GLuint index, const GLint64EXT *v) \
x(void, glVertexAttribL4i64vNV, PFNGLVERTEXATTRIBL4I64VNVPROC, GLuint index, const GLint64EXT *v) \
x(void, glVertexAttribL1ui64NV, PFNGLVERTEXATTRIBL1UI64NVPROC, GLuint index, GLuint64EXT x) \
x(void, glVertexAttribL2ui64NV, PFNGLVERTEXATTRIBL2UI64NVPROC, GLuint index, GLuint64EXT x, GLuint64EXT y) \
x(void, glVertexAttribL3ui64NV, PFNGLVERTEXATTRIBL3UI64NVPROC, GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) \
x(void, glVertexAttribL4ui64NV, PFNGLVERTEXATTRIBL4UI64NVPROC, GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) \
x(void, glVertexAttribL1ui64vNV, PFNGLVERTEXATTRIBL1UI64VNVPROC, GLuint index, const GLuint64EXT *v) \
x(void, glVertexAttribL2ui64vNV, PFNGLVERTEXATTRIBL2UI64VNVPROC, GLuint index, const GLuint64EXT *v) \
x(void, glVertexAttribL3ui64vNV, PFNGLVERTEXATTRIBL3UI64VNVPROC, GLuint index, const GLuint64EXT *v) \
x(void, glVertexAttribL4ui64vNV, PFNGLVERTEXATTRIBL4UI64VNVPROC, GLuint index, const GLuint64EXT *v) \
x(void, glGetVertexAttribLi64vNV, PFNGLGETVERTEXATTRIBLI64VNVPROC, GLuint index, GLenum pname, GLint64EXT *params) \
x(void, glGetVertexAttribLui64vNV, PFNGLGETVERTEXATTRIBLUI64VNVPROC, GLuint index, GLenum pname, GLuint64EXT *params) \
x(void, glVertexAttribLFormatNV, PFNGLVERTEXATTRIBLFORMATNVPROC, GLuint index, GLint size, GLenum type, GLsizei stride) \
x(void, glBufferAddressRangeNV, PFNGLBUFFERADDRESSRANGENVPROC, GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length) \
x(void, glVertexFormatNV, PFNGLVERTEXFORMATNVPROC, GLint size, GLenum type, GLsizei stride) \
x(void, glNormalFormatNV, PFNGLNORMALFORMATNVPROC, GLenum type, GLsizei stride) \
x(void, glColorFormatNV, PFNGLCOLORFORMATNVPROC, GLint size, GLenum type, GLsizei stride) \
x(void, glIndexFormatNV, PFNGLINDEXFORMATNVPROC, GLenum type, GLsizei stride) \
x(void, glTexCoordFormatNV, PFNGLTEXCOORDFORMATNVPROC, GLint size, GLenum type, GLsizei stride) \
x(void, glEdgeFlagFormatNV, PFNGLEDGEFLAGFORMATNVPROC, GLsizei stride) \
x(void, glSecondaryColorFormatNV, PFNGLSECONDARYCOLORFORMATNVPROC, GLint size, GLenum type, GLsizei stride) \
x(void, glFogCoordFormatNV, PFNGLFOGCOORDFORMATNVPROC, GLenum type, GLsizei stride) \
x(void, glVertexAttribFormatNV, PFNGLVERTEXATTRIBFORMATNVPROC, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride) \
x(void, glVertexAttribIFormatNV, PFNGLVERTEXATTRIBIFORMATNVPROC, GLuint index, GLint size, GLenum type, GLsizei stride) \
x(void, glGetIntegerui64i_vNV, PFNGLGETINTEGERUI64I_VNVPROC, GLenum value, GLuint index, GLuint64EXT *result) \
x(GLboolean, glAreProgramsResidentNV, PFNGLAREPROGRAMSRESIDENTNVPROC, GLsizei n, const GLuint *programs, GLboolean *residences) \
x(void, glBindProgramNV, PFNGLBINDPROGRAMNVPROC, GLenum target, GLuint id) \
x(void, glDeleteProgramsNV, PFNGLDELETEPROGRAMSNVPROC, GLsizei n, const GLuint *programs) \
x(void, glExecuteProgramNV, PFNGLEXECUTEPROGRAMNVPROC, GLenum target, GLuint id, const GLfloat *params) \
x(void, glGenProgramsNV, PFNGLGENPROGRAMSNVPROC, GLsizei n, GLuint *programs) \
x(void, glGetProgramParameterdvNV, PFNGLGETPROGRAMPARAMETERDVNVPROC, GLenum target, GLuint index, GLenum pname, GLdouble *params) \
x(void, glGetProgramParameterfvNV, PFNGLGETPROGRAMPARAMETERFVNVPROC, GLenum target, GLuint index, GLenum pname, GLfloat *params) \
x(void, glGetProgramivNV, PFNGLGETPROGRAMIVNVPROC, GLuint id, GLenum pname, GLint *params) \
x(void, glGetProgramStringNV, PFNGLGETPROGRAMSTRINGNVPROC, GLuint id, GLenum pname, GLubyte *program) \
x(void, glGetTrackMatrixivNV, PFNGLGETTRACKMATRIXIVNVPROC, GLenum target, GLuint address, GLenum pname, GLint *params) \
x(void, glGetVertexAttribdvNV, PFNGLGETVERTEXATTRIBDVNVPROC, GLuint index, GLenum pname, GLdouble *params) \
x(void, glGetVertexAttribfvNV, PFNGLGETVERTEXATTRIBFVNVPROC, GLuint index, GLenum pname, GLfloat *params) \
x(void, glGetVertexAttribivNV, PFNGLGETVERTEXATTRIBIVNVPROC, GLuint index, GLenum pname, GLint *params) \
x(void, glGetVertexAttribPointervNV, PFNGLGETVERTEXATTRIBPOINTERVNVPROC, GLuint index, GLenum pname, void **pointer) \
x(GLboolean, glIsProgramNV, PFNGLISPROGRAMNVPROC, GLuint id) \
x(void, glLoadProgramNV, PFNGLLOADPROGRAMNVPROC, GLenum target, GLuint id, GLsizei len, const GLubyte *program) \
x(void, glProgramParameter4dNV, PFNGLPROGRAMPARAMETER4DNVPROC, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glProgramParameter4dvNV, PFNGLPROGRAMPARAMETER4DVNVPROC, GLenum target, GLuint index, const GLdouble *v) \
x(void, glProgramParameter4fNV, PFNGLPROGRAMPARAMETER4FNVPROC, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glProgramParameter4fvNV, PFNGLPROGRAMPARAMETER4FVNVPROC, GLenum target, GLuint index, const GLfloat *v) \
x(void, glProgramParameters4dvNV, PFNGLPROGRAMPARAMETERS4DVNVPROC, GLenum target, GLuint index, GLsizei count, const GLdouble *v) \
x(void, glProgramParameters4fvNV, PFNGLPROGRAMPARAMETERS4FVNVPROC, GLenum target, GLuint index, GLsizei count, const GLfloat *v) \
x(void, glRequestResidentProgramsNV, PFNGLREQUESTRESIDENTPROGRAMSNVPROC, GLsizei n, const GLuint *programs) \
x(void, glTrackMatrixNV, PFNGLTRACKMATRIXNVPROC, GLenum target, GLuint address, GLenum matrix, GLenum transform) \
x(void, glVertexAttribPointerNV, PFNGLVERTEXATTRIBPOINTERNVPROC, GLuint index, GLint fsize, GLenum type, GLsizei stride, const void *pointer) \
x(void, glVertexAttrib1dNV, PFNGLVERTEXATTRIB1DNVPROC, GLuint index, GLdouble x) \
x(void, glVertexAttrib1dvNV, PFNGLVERTEXATTRIB1DVNVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib1fNV, PFNGLVERTEXATTRIB1FNVPROC, GLuint index, GLfloat x) \
x(void, glVertexAttrib1fvNV, PFNGLVERTEXATTRIB1FVNVPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib1sNV, PFNGLVERTEXATTRIB1SNVPROC, GLuint index, GLshort x) \
x(void, glVertexAttrib1svNV, PFNGLVERTEXATTRIB1SVNVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib2dNV, PFNGLVERTEXATTRIB2DNVPROC, GLuint index, GLdouble x, GLdouble y) \
x(void, glVertexAttrib2dvNV, PFNGLVERTEXATTRIB2DVNVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib2fNV, PFNGLVERTEXATTRIB2FNVPROC, GLuint index, GLfloat x, GLfloat y) \
x(void, glVertexAttrib2fvNV, PFNGLVERTEXATTRIB2FVNVPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib2sNV, PFNGLVERTEXATTRIB2SNVPROC, GLuint index, GLshort x, GLshort y) \
x(void, glVertexAttrib2svNV, PFNGLVERTEXATTRIB2SVNVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib3dNV, PFNGLVERTEXATTRIB3DNVPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z) \
x(void, glVertexAttrib3dvNV, PFNGLVERTEXATTRIB3DVNVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib3fNV, PFNGLVERTEXATTRIB3FNVPROC, GLuint index, GLfloat x, GLfloat y, GLfloat z) \
x(void, glVertexAttrib3fvNV, PFNGLVERTEXATTRIB3FVNVPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib3sNV, PFNGLVERTEXATTRIB3SNVPROC, GLuint index, GLshort x, GLshort y, GLshort z) \
x(void, glVertexAttrib3svNV, PFNGLVERTEXATTRIB3SVNVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib4dNV, PFNGLVERTEXATTRIB4DNVPROC, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) \
x(void, glVertexAttrib4dvNV, PFNGLVERTEXATTRIB4DVNVPROC, GLuint index, const GLdouble *v) \
x(void, glVertexAttrib4fNV, PFNGLVERTEXATTRIB4FNVPROC, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glVertexAttrib4fvNV, PFNGLVERTEXATTRIB4FVNVPROC, GLuint index, const GLfloat *v) \
x(void, glVertexAttrib4sNV, PFNGLVERTEXATTRIB4SNVPROC, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) \
x(void, glVertexAttrib4svNV, PFNGLVERTEXATTRIB4SVNVPROC, GLuint index, const GLshort *v) \
x(void, glVertexAttrib4ubNV, PFNGLVERTEXATTRIB4UBNVPROC, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) \
x(void, glVertexAttrib4ubvNV, PFNGLVERTEXATTRIB4UBVNVPROC, GLuint index, const GLubyte *v) \
x(void, glVertexAttribs1dvNV, PFNGLVERTEXATTRIBS1DVNVPROC, GLuint index, GLsizei count, const GLdouble *v) \
x(void, glVertexAttribs1fvNV, PFNGLVERTEXATTRIBS1FVNVPROC, GLuint index, GLsizei count, const GLfloat *v) \
x(void, glVertexAttribs1svNV, PFNGLVERTEXATTRIBS1SVNVPROC, GLuint index, GLsizei count, const GLshort *v) \
x(void, glVertexAttribs2dvNV, PFNGLVERTEXATTRIBS2DVNVPROC, GLuint index, GLsizei count, const GLdouble *v) \
x(void, glVertexAttribs2fvNV, PFNGLVERTEXATTRIBS2FVNVPROC, GLuint index, GLsizei count, const GLfloat *v) \
x(void, glVertexAttribs2svNV, PFNGLVERTEXATTRIBS2SVNVPROC, GLuint index, GLsizei count, const GLshort *v) \
x(void, glVertexAttribs3dvNV, PFNGLVERTEXATTRIBS3DVNVPROC, GLuint index, GLsizei count, const GLdouble *v) \
x(void, glVertexAttribs3fvNV, PFNGLVERTEXATTRIBS3FVNVPROC, GLuint index, GLsizei count, const GLfloat *v) \
x(void, glVertexAttribs3svNV, PFNGLVERTEXATTRIBS3SVNVPROC, GLuint index, GLsizei count, const GLshort *v) \
x(void, glVertexAttribs4dvNV, PFNGLVERTEXATTRIBS4DVNVPROC, GLuint index, GLsizei count, const GLdouble *v) \
x(void, glVertexAttribs4fvNV, PFNGLVERTEXATTRIBS4FVNVPROC, GLuint index, GLsizei count, const GLfloat *v) \
x(void, glVertexAttribs4svNV, PFNGLVERTEXATTRIBS4SVNVPROC, GLuint index, GLsizei count, const GLshort *v) \
x(void, glVertexAttribs4ubvNV, PFNGLVERTEXATTRIBS4UBVNVPROC, GLuint index, GLsizei count, const GLubyte *v) \
x(void, glBeginVideoCaptureNV, PFNGLBEGINVIDEOCAPTURENVPROC, GLuint video_capture_slot) \
x(void, glBindVideoCaptureStreamBufferNV, PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC, GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset) \
x(void, glBindVideoCaptureStreamTextureNV, PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC, GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture) \
x(void, glEndVideoCaptureNV, PFNGLENDVIDEOCAPTURENVPROC, GLuint video_capture_slot) \
x(void, glGetVideoCaptureivNV, PFNGLGETVIDEOCAPTUREIVNVPROC, GLuint video_capture_slot, GLenum pname, GLint *params) \
x(void, glGetVideoCaptureStreamivNV, PFNGLGETVIDEOCAPTURESTREAMIVNVPROC, GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params) \
x(void, glGetVideoCaptureStreamfvNV, PFNGLGETVIDEOCAPTURESTREAMFVNVPROC, GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params) \
x(void, glGetVideoCaptureStreamdvNV, PFNGLGETVIDEOCAPTURESTREAMDVNVPROC, GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params) \
x(GLenum, glVideoCaptureNV, PFNGLVIDEOCAPTURENVPROC, GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time) \
x(void, glVideoCaptureStreamParameterivNV, PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC, GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params) \
x(void, glVideoCaptureStreamParameterfvNV, PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC, GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params) \
x(void, glVideoCaptureStreamParameterdvNV, PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC, GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params) \
x(void, glViewportSwizzleNV, PFNGLVIEWPORTSWIZZLENVPROC, GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew) \
x(void, glFramebufferTextureMultiviewOVR, PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews) \
x(void, glHintPGI, PFNGLHINTPGIPROC, GLenum target, GLint mode) \
x(void, glDetailTexFuncSGIS, PFNGLDETAILTEXFUNCSGISPROC, GLenum target, GLsizei n, const GLfloat *points) \
x(void, glGetDetailTexFuncSGIS, PFNGLGETDETAILTEXFUNCSGISPROC, GLenum target, GLfloat *points) \
x(void, glFogFuncSGIS, PFNGLFOGFUNCSGISPROC, GLsizei n, const GLfloat *points) \
x(void, glGetFogFuncSGIS, PFNGLGETFOGFUNCSGISPROC, GLfloat *points) \
x(void, glSampleMaskSGIS, PFNGLSAMPLEMASKSGISPROC, GLclampf value, GLboolean invert) \
x(void, glSamplePatternSGIS, PFNGLSAMPLEPATTERNSGISPROC, GLenum pattern) \
x(void, glPixelTexGenParameteriSGIS, PFNGLPIXELTEXGENPARAMETERISGISPROC, GLenum pname, GLint param) \
x(void, glPixelTexGenParameterivSGIS, PFNGLPIXELTEXGENPARAMETERIVSGISPROC, GLenum pname, const GLint *params) \
x(void, glPixelTexGenParameterfSGIS, PFNGLPIXELTEXGENPARAMETERFSGISPROC, GLenum pname, GLfloat param) \
x(void, glPixelTexGenParameterfvSGIS, PFNGLPIXELTEXGENPARAMETERFVSGISPROC, GLenum pname, const GLfloat *params) \
x(void, glGetPixelTexGenParameterivSGIS, PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC, GLenum pname, GLint *params) \
x(void, glGetPixelTexGenParameterfvSGIS, PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC, GLenum pname, GLfloat *params) \
x(void, glPointParameterfSGIS, PFNGLPOINTPARAMETERFSGISPROC, GLenum pname, GLfloat param) \
x(void, glPointParameterfvSGIS, PFNGLPOINTPARAMETERFVSGISPROC, GLenum pname, const GLfloat *params) \
x(void, glSharpenTexFuncSGIS, PFNGLSHARPENTEXFUNCSGISPROC, GLenum target, GLsizei n, const GLfloat *points) \
x(void, glGetSharpenTexFuncSGIS, PFNGLGETSHARPENTEXFUNCSGISPROC, GLenum target, GLfloat *points) \
x(void, glTexImage4DSGIS, PFNGLTEXIMAGE4DSGISPROC, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void *pixels) \
x(void, glTexSubImage4DSGIS, PFNGLTEXSUBIMAGE4DSGISPROC, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void *pixels) \
x(void, glTextureColorMaskSGIS, PFNGLTEXTURECOLORMASKSGISPROC, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) \
x(void, glGetTexFilterFuncSGIS, PFNGLGETTEXFILTERFUNCSGISPROC, GLenum target, GLenum filter, GLfloat *weights) \
x(void, glTexFilterFuncSGIS, PFNGLTEXFILTERFUNCSGISPROC, GLenum target, GLenum filter, GLsizei n, const GLfloat *weights) \
x(void, glAsyncMarkerSGIX, PFNGLASYNCMARKERSGIXPROC, GLuint marker) \
x(GLint, glFinishAsyncSGIX, PFNGLFINISHASYNCSGIXPROC, GLuint *markerp) \
x(GLint, glPollAsyncSGIX, PFNGLPOLLASYNCSGIXPROC, GLuint *markerp) \
x(GLuint, glGenAsyncMarkersSGIX, PFNGLGENASYNCMARKERSSGIXPROC, GLsizei range) \
x(void, glDeleteAsyncMarkersSGIX, PFNGLDELETEASYNCMARKERSSGIXPROC, GLuint marker, GLsizei range) \
x(GLboolean, glIsAsyncMarkerSGIX, PFNGLISASYNCMARKERSGIXPROC, GLuint marker) \
x(void, glFlushRasterSGIX, PFNGLFLUSHRASTERSGIXPROC, void) \
x(void, glFragmentColorMaterialSGIX, PFNGLFRAGMENTCOLORMATERIALSGIXPROC, GLenum face, GLenum mode) \
x(void, glFragmentLightfSGIX, PFNGLFRAGMENTLIGHTFSGIXPROC, GLenum light, GLenum pname, GLfloat param) \
x(void, glFragmentLightfvSGIX, PFNGLFRAGMENTLIGHTFVSGIXPROC, GLenum light, GLenum pname, const GLfloat *params) \
x(void, glFragmentLightiSGIX, PFNGLFRAGMENTLIGHTISGIXPROC, GLenum light, GLenum pname, GLint param) \
x(void, glFragmentLightivSGIX, PFNGLFRAGMENTLIGHTIVSGIXPROC, GLenum light, GLenum pname, const GLint *params) \
x(void, glFragmentLightModelfSGIX, PFNGLFRAGMENTLIGHTMODELFSGIXPROC, GLenum pname, GLfloat param) \
x(void, glFragmentLightModelfvSGIX, PFNGLFRAGMENTLIGHTMODELFVSGIXPROC, GLenum pname, const GLfloat *params) \
x(void, glFragmentLightModeliSGIX, PFNGLFRAGMENTLIGHTMODELISGIXPROC, GLenum pname, GLint param) \
x(void, glFragmentLightModelivSGIX, PFNGLFRAGMENTLIGHTMODELIVSGIXPROC, GLenum pname, const GLint *params) \
x(void, glFragmentMaterialfSGIX, PFNGLFRAGMENTMATERIALFSGIXPROC, GLenum face, GLenum pname, GLfloat param) \
x(void, glFragmentMaterialfvSGIX, PFNGLFRAGMENTMATERIALFVSGIXPROC, GLenum face, GLenum pname, const GLfloat *params) \
x(void, glFragmentMaterialiSGIX, PFNGLFRAGMENTMATERIALISGIXPROC, GLenum face, GLenum pname, GLint param) \
x(void, glFragmentMaterialivSGIX, PFNGLFRAGMENTMATERIALIVSGIXPROC, GLenum face, GLenum pname, const GLint *params) \
x(void, glGetFragmentLightfvSGIX, PFNGLGETFRAGMENTLIGHTFVSGIXPROC, GLenum light, GLenum pname, GLfloat *params) \
x(void, glGetFragmentLightivSGIX, PFNGLGETFRAGMENTLIGHTIVSGIXPROC, GLenum light, GLenum pname, GLint *params) \
x(void, glGetFragmentMaterialfvSGIX, PFNGLGETFRAGMENTMATERIALFVSGIXPROC, GLenum face, GLenum pname, GLfloat *params) \
x(void, glGetFragmentMaterialivSGIX, PFNGLGETFRAGMENTMATERIALIVSGIXPROC, GLenum face, GLenum pname, GLint *params) \
x(void, glLightEnviSGIX, PFNGLLIGHTENVISGIXPROC, GLenum pname, GLint param) \
x(void, glFrameZoomSGIX, PFNGLFRAMEZOOMSGIXPROC, GLint factor) \
x(void, glIglooInterfaceSGIX, PFNGLIGLOOINTERFACESGIXPROC, GLenum pname, const void *params) \
x(GLint, glGetInstrumentsSGIX, PFNGLGETINSTRUMENTSSGIXPROC, void) \
x(void, glInstrumentsBufferSGIX, PFNGLINSTRUMENTSBUFFERSGIXPROC, GLsizei size, GLint *buffer) \
x(GLint, glPollInstrumentsSGIX, PFNGLPOLLINSTRUMENTSSGIXPROC, GLint *marker_p) \
x(void, glReadInstrumentsSGIX, PFNGLREADINSTRUMENTSSGIXPROC, GLint marker) \
x(void, glStartInstrumentsSGIX, PFNGLSTARTINSTRUMENTSSGIXPROC, void) \
x(void, glStopInstrumentsSGIX, PFNGLSTOPINSTRUMENTSSGIXPROC, GLint marker) \
x(void, glGetListParameterfvSGIX, PFNGLGETLISTPARAMETERFVSGIXPROC, GLuint list, GLenum pname, GLfloat *params) \
x(void, glGetListParameterivSGIX, PFNGLGETLISTPARAMETERIVSGIXPROC, GLuint list, GLenum pname, GLint *params) \
x(void, glListParameterfSGIX, PFNGLLISTPARAMETERFSGIXPROC, GLuint list, GLenum pname, GLfloat param) \
x(void, glListParameterfvSGIX, PFNGLLISTPARAMETERFVSGIXPROC, GLuint list, GLenum pname, const GLfloat *params) \
x(void, glListParameteriSGIX, PFNGLLISTPARAMETERISGIXPROC, GLuint list, GLenum pname, GLint param) \
x(void, glListParameterivSGIX, PFNGLLISTPARAMETERIVSGIXPROC, GLuint list, GLenum pname, const GLint *params) \
x(void, glPixelTexGenSGIX, PFNGLPIXELTEXGENSGIXPROC, GLenum mode) \
x(void, glDeformationMap3dSGIX, PFNGLDEFORMATIONMAP3DSGIXPROC, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points) \
x(void, glDeformationMap3fSGIX, PFNGLDEFORMATIONMAP3FSGIXPROC, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points) \
x(void, glDeformSGIX, PFNGLDEFORMSGIXPROC, GLbitfield mask) \
x(void, glLoadIdentityDeformationMapSGIX, PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC, GLbitfield mask) \
x(void, glReferencePlaneSGIX, PFNGLREFERENCEPLANESGIXPROC, const GLdouble *equation) \
x(void, glSpriteParameterfSGIX, PFNGLSPRITEPARAMETERFSGIXPROC, GLenum pname, GLfloat param) \
x(void, glSpriteParameterfvSGIX, PFNGLSPRITEPARAMETERFVSGIXPROC, GLenum pname, const GLfloat *params) \
x(void, glSpriteParameteriSGIX, PFNGLSPRITEPARAMETERISGIXPROC, GLenum pname, GLint param) \
x(void, glSpriteParameterivSGIX, PFNGLSPRITEPARAMETERIVSGIXPROC, GLenum pname, const GLint *params) \
x(void, glTagSampleBufferSGIX, PFNGLTAGSAMPLEBUFFERSGIXPROC, void) \
x(void, glColorTableSGI, PFNGLCOLORTABLESGIPROC, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table) \
x(void, glColorTableParameterfvSGI, PFNGLCOLORTABLEPARAMETERFVSGIPROC, GLenum target, GLenum pname, const GLfloat *params) \
x(void, glColorTableParameterivSGI, PFNGLCOLORTABLEPARAMETERIVSGIPROC, GLenum target, GLenum pname, const GLint *params) \
x(void, glCopyColorTableSGI, PFNGLCOPYCOLORTABLESGIPROC, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) \
x(void, glGetColorTableSGI, PFNGLGETCOLORTABLESGIPROC, GLenum target, GLenum format, GLenum type, void *table) \
x(void, glGetColorTableParameterfvSGI, PFNGLGETCOLORTABLEPARAMETERFVSGIPROC, GLenum target, GLenum pname, GLfloat *params) \
x(void, glGetColorTableParameterivSGI, PFNGLGETCOLORTABLEPARAMETERIVSGIPROC, GLenum target, GLenum pname, GLint *params) \
x(void, glFinishTextureSUNX, PFNGLFINISHTEXTURESUNXPROC, void) \
x(void, glGlobalAlphaFactorbSUN, PFNGLGLOBALALPHAFACTORBSUNPROC, GLbyte factor) \
x(void, glGlobalAlphaFactorsSUN, PFNGLGLOBALALPHAFACTORSSUNPROC, GLshort factor) \
x(void, glGlobalAlphaFactoriSUN, PFNGLGLOBALALPHAFACTORISUNPROC, GLint factor) \
x(void, glGlobalAlphaFactorfSUN, PFNGLGLOBALALPHAFACTORFSUNPROC, GLfloat factor) \
x(void, glGlobalAlphaFactordSUN, PFNGLGLOBALALPHAFACTORDSUNPROC, GLdouble factor) \
x(void, glGlobalAlphaFactorubSUN, PFNGLGLOBALALPHAFACTORUBSUNPROC, GLubyte factor) \
x(void, glGlobalAlphaFactorusSUN, PFNGLGLOBALALPHAFACTORUSSUNPROC, GLushort factor) \
x(void, glGlobalAlphaFactoruiSUN, PFNGLGLOBALALPHAFACTORUISUNPROC, GLuint factor) \
x(void, glDrawMeshArraysSUN, PFNGLDRAWMESHARRAYSSUNPROC, GLenum mode, GLint first, GLsizei count, GLsizei width) \
x(void, glReplacementCodeuiSUN, PFNGLREPLACEMENTCODEUISUNPROC, GLuint code) \
x(void, glReplacementCodeusSUN, PFNGLREPLACEMENTCODEUSSUNPROC, GLushort code) \
x(void, glReplacementCodeubSUN, PFNGLREPLACEMENTCODEUBSUNPROC, GLubyte code) \
x(void, glReplacementCodeuivSUN, PFNGLREPLACEMENTCODEUIVSUNPROC, const GLuint *code) \
x(void, glReplacementCodeusvSUN, PFNGLREPLACEMENTCODEUSVSUNPROC, const GLushort *code) \
x(void, glReplacementCodeubvSUN, PFNGLREPLACEMENTCODEUBVSUNPROC, const GLubyte *code) \
x(void, glReplacementCodePointerSUN, PFNGLREPLACEMENTCODEPOINTERSUNPROC, GLenum type, GLsizei stride, const void **pointer) \
x(void, glColor4ubVertex2fSUN, PFNGLCOLOR4UBVERTEX2FSUNPROC, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y) \
x(void, glColor4ubVertex2fvSUN, PFNGLCOLOR4UBVERTEX2FVSUNPROC, const GLubyte *c, const GLfloat *v) \
x(void, glColor4ubVertex3fSUN, PFNGLCOLOR4UBVERTEX3FSUNPROC, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) \
x(void, glColor4ubVertex3fvSUN, PFNGLCOLOR4UBVERTEX3FVSUNPROC, const GLubyte *c, const GLfloat *v) \
x(void, glColor3fVertex3fSUN, PFNGLCOLOR3FVERTEX3FSUNPROC, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) \
x(void, glColor3fVertex3fvSUN, PFNGLCOLOR3FVERTEX3FVSUNPROC, const GLfloat *c, const GLfloat *v) \
x(void, glNormal3fVertex3fSUN, PFNGLNORMAL3FVERTEX3FSUNPROC, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) \
x(void, glNormal3fVertex3fvSUN, PFNGLNORMAL3FVERTEX3FVSUNPROC, const GLfloat *n, const GLfloat *v) \
x(void, glColor4fNormal3fVertex3fSUN, PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) \
x(void, glColor4fNormal3fVertex3fvSUN, PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC, const GLfloat *c, const GLfloat *n, const GLfloat *v) \
x(void, glTexCoord2fVertex3fSUN, PFNGLTEXCOORD2FVERTEX3FSUNPROC, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) \
x(void, glTexCoord2fVertex3fvSUN, PFNGLTEXCOORD2FVERTEX3FVSUNPROC, const GLfloat *tc, const GLfloat *v) \
x(void, glTexCoord4fVertex4fSUN, PFNGLTEXCOORD4FVERTEX4FSUNPROC, GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glTexCoord4fVertex4fvSUN, PFNGLTEXCOORD4FVERTEX4FVSUNPROC, const GLfloat *tc, const GLfloat *v) \
x(void, glTexCoord2fColor4ubVertex3fSUN, PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC, GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) \
x(void, glTexCoord2fColor4ubVertex3fvSUN, PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC, const GLfloat *tc, const GLubyte *c, const GLfloat *v) \
x(void, glTexCoord2fColor3fVertex3fSUN, PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) \
x(void, glTexCoord2fColor3fVertex3fvSUN, PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC, const GLfloat *tc, const GLfloat *c, const GLfloat *v) \
x(void, glTexCoord2fNormal3fVertex3fSUN, PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) \
x(void, glTexCoord2fNormal3fVertex3fvSUN, PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC, const GLfloat *tc, const GLfloat *n, const GLfloat *v) \
x(void, glTexCoord2fColor4fNormal3fVertex3fSUN, PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) \
x(void, glTexCoord2fColor4fNormal3fVertex3fvSUN, PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v) \
x(void, glTexCoord4fColor4fNormal3fVertex4fSUN, PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC, GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w) \
x(void, glTexCoord4fColor4fNormal3fVertex4fvSUN, PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v) \
x(void, glReplacementCodeuiVertex3fSUN, PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC, GLuint rc, GLfloat x, GLfloat y, GLfloat z) \
x(void, glReplacementCodeuiVertex3fvSUN, PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC, const GLuint *rc, const GLfloat *v) \
x(void, glReplacementCodeuiColor4ubVertex3fSUN, PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC, GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) \
x(void, glReplacementCodeuiColor4ubVertex3fvSUN, PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC, const GLuint *rc, const GLubyte *c, const GLfloat *v) \
x(void, glReplacementCodeuiColor3fVertex3fSUN, PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC, GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) \
x(void, glReplacementCodeuiColor3fVertex3fvSUN, PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC, const GLuint *rc, const GLfloat *c, const GLfloat *v) \
x(void, glReplacementCodeuiNormal3fVertex3fSUN, PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC, GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) \
x(void, glReplacementCodeuiNormal3fVertex3fvSUN, PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC, const GLuint *rc, const GLfloat *n, const GLfloat *v) \
x(void, glReplacementCodeuiColor4fNormal3fVertex3fSUN, PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC, GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) \
x(void, glReplacementCodeuiColor4fNormal3fVertex3fvSUN, PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC, const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v) \
x(void, glReplacementCodeuiTexCoord2fVertex3fSUN, PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC, GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) \
x(void, glReplacementCodeuiTexCoord2fVertex3fvSUN, PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC, const GLuint *rc, const GLfloat *tc, const GLfloat *v) \
x(void, glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN, PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC, GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) \
x(void, glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN, PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC, const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v) \
x(void, glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN, PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC, GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) \
x(void, glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN, PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC, const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v) \
*/