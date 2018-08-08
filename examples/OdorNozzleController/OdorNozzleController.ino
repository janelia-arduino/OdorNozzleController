#include <OdorNozzleController.h>


OdorNozzleController dev;

void setup()
{
  dev.setup();
  dev.startServer();
}

void loop()
{
  dev.update();
}
