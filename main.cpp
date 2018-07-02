#include "vec2D.h"

int main(int argc, char* stuff[])
{
    vec2 null(0);
    vec2 one(1);
    std::cout << (int)null.x << " " << (int)null.y << std::endl;
    std::cout << (int)null.data[0] << " " << (int)null.data[1] << std::endl;
    std::cout << null.getHash() << std::endl;
    std::cout << one.getHash() << std::endl;
    vec2 two = one+one;
    std::cout << two.getHash() << std::endl;
    two+=null;
    std::cout << two.getHash() << std::endl;
    std::cout << null << std::endl
        << one << std::endl
        << two << std::endl;
    std::cout << "manhattan: " << two.distManhattan(null) << std::endl;
    two.x+=1;
    std::cout << "manhattan: " << two.distManhattan(null) << std::endl;
    return 0;
}
