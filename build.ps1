# compile
Write-Output "compiling..."
g++ -c -std=c++17 ".\src\\server\\server.cpp" -o ".\\out\\server\\server.out" -I./include -I./src
g++ -c -std=c++17 ".\src\\client\\client.cpp" -o ".\\out\\client\\client.out" -I./include -I./src
# link
Write-Output "linking..."
g++ ".\\out\\server\\server.out" -o ".\\out\\server\\server.exe" -L./lib -lsfml-system -lsfml-network
g++ ".\\out\\client\\client.out" -o ".\\out\\client\\client.exe" -L./lib -lsfml-system -lsfml-network