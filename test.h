class __attribute__ ((visibility("default"))) Test
{
public:
    Test();
    virtual ~Test();

#if DOCONSTPLZ
    #warning CONST HERE
    virtual void test(int a, float b, double c) const = 0;
#else
    #warning NO CONST HERE
    virtual void test(int a, float b, double c) = 0;
#endif
};
