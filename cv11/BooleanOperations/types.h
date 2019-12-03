#ifndef TYPES_H
#define TYPES_H

//Position of point and line
typedef enum
{
  LeftHp = 0,
  RightHp = 1,
  Colinear = 2

}TPointLinePosition;

//Position of point and polygon
typedef enum
{
    Inner,
    Outer,
    On

}TPointPolygonPosition;

//Define boolean operations
typedef enum
{
    Union,
    Intersect,
    DifferenceAB,
    DifferenceBA

}TBooleanOparation;

//2 Line position
typedef enum
{
  Paralel,
  Identical,
  NonIntersected,
  Intersected

}T2LinesPosition;

#endif // TYPES_H
