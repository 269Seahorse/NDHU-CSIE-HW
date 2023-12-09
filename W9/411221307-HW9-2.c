int main() {
  int *p;
  init(&p);
  printf("%d, %d", *(p + 4), *(p + 31));
  return 0;
}
