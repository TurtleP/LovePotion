class Drawable : public Object
{
    public:
        Drawable(char * type);
        Drawable() {};
        void Draw(float x, float y, float rotation, float scalarX, float scalarY, Color color);

        int GetWidth();
        int GetHeight();

        Tex3DS_SubTexture GetSubTexture();
        void SetSubTexture(const Tex3DS_SubTexture & subTexture);

    protected:
        u32 * LoadPNG(const char * path, char * buffer, size_t memorySize);
        u32 NextPO2(u32 in);

        void LoadImage(u32 * buffer);

        int width;
        int height;

        C2D_Image image;
        Tex3DS_SubTexture subTexture;
};