// Задача 9. Треугольник на координатной плоскости.

// Проверьте, образуют ли треугольник три данные точки на координатной
// плоскости. Каждая точка задается двумя координатами. Таким образом, на вход
// программе дается 6 чисел: координаты первой точки, затем координаты второй
// точки и координаты третьей точки. Программа должна ответить “Yes”, если три
// данные точки задают треугольник, и “No” иначе.

// Например, если хотя бы две из данных точек совпадают, то треугольника данные
// три точки не образуют. Другой пример: точки с координатами (1; 2), (3; 6) и
// (-2; -4) не образуют треугольника, поскольку они лежат на одной прямой, хоть
// и не совпадают.

// Постарайтесь сделать свою программу по возможности лаконичнее.

// Подсказка. Три точки А, B и С будут лежать на одной прямой, если совпадают
// углы наклона прямых, проведенных через любые две пары точек (например,
// совпадают прямые АВ и ВС).

// Угол можно проверить с помощью формулы (a-x)/(b-y), где a и b  координаты
// первой точки, а x и y  координаты второй.

#include <cmath>
#include <iostream>

int main() {
  std::cout << "Введите координаты первой точки (x y), например, 1 2:";
  int firstX, firstY;
  std::cin >> firstX >> firstY;

  std::cout << "Введите координаты второй точки (x y), например, 3 4:";
  int secondX, secondY;
  std::cin >> secondX >> secondY;

  std::cout << "Введите координаты третьей точки (x y), например, 5 6:";
  int thirdX, thirdY;
  std::cin >> thirdX >> thirdY;

  bool doPointsDefineTriangle = true;
  if ((firstX == secondX && firstY == secondY) ||
      (firstX == thirdX && firstY == thirdY) ||
      (secondX == thirdX && secondY == thirdY)) {
    doPointsDefineTriangle = false;
  } else {
    // Угол можно проверить с помощью формулы (a-x)/(b-y), где a и b  координаты
    // первой точки, а x и y  координаты второй.
    //
    // So we have:
    // ANGLE1 = (X1-X2)/(Y1-Y2)
    // ANGLE2 = (X1-X3)/(Y1-Y3)
    // ANGLE1 == ANGLE
    // (X1-X2)/(Y1-Y2) == (X1-X3)/(Y1-Y3)
    // To avoid division by zero, we may rewrite as:
    // (X1-X2) * (Y1-Y3) == (X1-X3) * (Y1-Y2)
    if ((firstX - secondX) * (firstY - thirdY) ==
        (firstY - secondY) * (firstX - thirdX)) {
      doPointsDefineTriangle = false;
    }
  }

  if (doPointsDefineTriangle) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
