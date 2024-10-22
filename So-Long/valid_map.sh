echo "Test 1"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid.ber
echo "=================================================================="

echo "Test 2"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_1.ber
echo "=================================================================="

echo "Test 3"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_2.ber
echo "=================================================================="

echo "Test 4"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_4.ber
echo "=================================================================="

echo "Test 6"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_5.ber
echo "=================================================================="

echo "Test 7"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_6.ber
echo "=================================================================="

echo "Test 8"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_7.ber
echo "=================================================================="

echo "Test 9"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_8.ber
echo "=================================================================="

echo "Test 10"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_9.ber
echo "=================================================================="

echo "Test 11"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_10.ber
echo "=================================================================="

echo "Test 12"
valgrind --leak-check=full --show-leak-kinds=all ./so_long map/valid/valid_11.ber
echo "=================================================================="
