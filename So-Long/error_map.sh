echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/...ber
echo "=================================================================="

echo "Test 2"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/.ber
echo "=================================================================="

echo "Test 3"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/badextension1.txt
echo "=================================================================="

echo "Test 4"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/badextension2.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/badextension3....bber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/empty.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/illegal_chars.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/illegal_chars1.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/illegal_chars2.ber
echo "=================================================================="


echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/illegal_chars3.ber
echo "=================================================================="


echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/illegal_chars4.ber
echo "=================================================================="


echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/invalid_dim.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/invalid_dim1.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/invalid_dim2.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/invalid_dim3.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/invalid_dim4.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/multiple_exit.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/multiple_player.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_exit.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_object.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_player.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_road.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_road1.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_road2.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_road3.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_road4.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_walls.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_walls1.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_walls2.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_walls3.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/no_walls4.ber
echo "=================================================================="

echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/error/too_big.ber
echo "=================================================================="

