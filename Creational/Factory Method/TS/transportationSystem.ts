/*
    Develop a transportation management system that handles different modes of transportation (e.g., trucks, ships, airplanes). Use the Factory Method pattern to create transportation objects. Each mode of transportation should have a method like transportCargo().
*/

interface Transportation {
  transportCargo(): void;
}

class Truck implements Transportation {
  transportCargo(): void {
    console.log("Truck is transporting cargo");
  }
}

class Ship implements Transportation {
  transportCargo(): void {
    console.log("Ship is transporting cargo");
  }
}

class Airplane implements Transportation {
  transportCargo(): void {
    console.log("Airplane is transporting cargo");
  }
}

interface TransportationFactory {
  createTransportation(): Transportation;
}

class TruckFactory implements TransportationFactory {
  createTransportation(): Transportation {
    return new Truck();
  }
}

class ShipFactory implements TransportationFactory {
  createTransportation(): Transportation {
    return new Ship();
  }
}

class AirplaneFactory implements TransportationFactory {
  createTransportation(): Transportation {
    return new Airplane();
  }
}

const truckFactory = new TruckFactory();
const truck = truckFactory.createTransportation();
truck.transportCargo();

const shipFactory = new ShipFactory();
const ship = shipFactory.createTransportation();
ship.transportCargo();

const airplaneFactory = new AirplaneFactory();
const airplane = airplaneFactory.createTransportation();
airplane.transportCargo();
