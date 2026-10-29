package Snippets.notes.Java;
import java.util.Collections;
import java.util.List;

public interface RemoteControlCar {
    // TODO implement the RemoteControlCar interface
    void drive();

    int getDistanceTravelled();
}


class ProductionRemoteControlCar implements RemoteControlCar, Comparable<ProductionRemoteControlCar> {

    private int distanceTravelled = 0;
    private int victories = 0;

    public void drive() {
        this.distanceTravelled += 10;
    }

    public int getDistanceTravelled() {
        return this.distanceTravelled;
    }

    public int getNumberOfVictories() {
        return this.victories;
    }

    public void setNumberOfVictories(int numberOfVictories) {
        this.victories = numberOfVictories;
    }


    @Override
    public int compareTo(ProductionRemoteControlCar o) {
        return Integer.compare(o.victories, this.victories);
    }
}


public class TestTrack {

    public static void race(RemoteControlCar car) {
        car.drive();
    }

    public static List<ProductionRemoteControlCar> getRankedCars(List<ProductionRemoteControlCar> cars) {
        Collections.sort(cars);
        return cars;
    }
}
