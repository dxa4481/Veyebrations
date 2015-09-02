class Proximity {
 public:
  Proximity(int32_t echoPin, int32_t trigPin);
  double getProximity();
 private:
  int32_t echoPin;
  int32_t trigPin;
  Temperature temp;
};
