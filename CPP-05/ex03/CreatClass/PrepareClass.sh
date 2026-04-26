cd ./CreatClass
c++ prepare_class.cpp
cd ..

res=$(./CreatClass/a.out u $2)
res2=$(./CreatClass/a.out upper $2)

if [ $1 = "-c" ]; then
    touch "$res.hpp"
    touch "$res.cpp"
    echo "#ifndef $res2""_HPP" >> "$res.hpp"
    echo "#define $res2""_HPP" >> "$res.hpp"
    echo "class $res{
    private:
    public:
        "$res""\(void\)""\;"
        ~"$res""\(void\)""\;"
        $res "\(const $res "&obj"\)\;"
        $res "\&operator=\(const $res \&obj\)";

    };" >> "$res.hpp"
    echo "#endif" >> "$res.hpp"
    echo "#include \"$res.hpp\"" >> $res.cpp
    echo "$res::$res(void)
{

}"  >> $res.cpp
echo "$res::~$res()
{

}"  >> $res.cpp
echo "$res::$res(const $res &obj)
{

}"  >> $res.cpp

echo "$res &$res::operator=(const $res &obj)
{

}"  >> $res.cpp
fi