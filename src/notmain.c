#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void calc_distance(uint8_t, uint8_t);

struct distance {
  uint8_t An;
  uint8_t Bn;
};

int main() {
  struct distance d = {
      10,
      34,
  };

  calc_distance(d.An, d.Bn);
}

void calc_distance(uint8_t A, uint8_t B) {
  uint8_t distance_between_points = B - A;
  printf("%d", distance_between_points);
}
