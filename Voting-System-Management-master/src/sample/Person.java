package sample;

import javafx.beans.property.SimpleStringProperty;
import javafx.scene.control.ToggleGroup;

import java.time.LocalDate;

public class Person {
    private SimpleStringProperty voterName;
    private LocalDate voterDateOfBirth;
    private SimpleStringProperty voterSex;
    private SimpleStringProperty voterPhoneNumber;
    private SimpleStringProperty voterVoterID;
    private SimpleStringProperty voterPassword;

    public Person(String voterName, LocalDate voterDateOfBirth, String voterSex, String voterPhoneNumber, String voterVoterID, String voterPassword) {
        this.voterName = new SimpleStringProperty(voterName);
        this.voterDateOfBirth = voterDateOfBirth;
        this.voterSex = new SimpleStringProperty(voterSex);
        this.voterPhoneNumber = new SimpleStringProperty(voterPhoneNumber);
        this.voterVoterID = new SimpleStringProperty(voterVoterID);
        this.voterPassword = new SimpleStringProperty(voterPassword);
    }


    public String getVoterName() {
        return voterName.get();
    }

    public SimpleStringProperty voterNameProperty() {
        return voterName;
    }

    public void setVoterName(String voterName) {
        this.voterName.set(voterName);
    }


    public LocalDate getVoterDateOfBirth() {
        return voterDateOfBirth;
    }

    public void setVoterDateOfBirth(LocalDate voterDateOfBirth) {
        this.voterDateOfBirth = voterDateOfBirth;
    }

    public String getVoterSex() {
        return voterSex.get();
    }

    public void setVoterSex(String voterSex) {
        this.voterSex.set(voterSex);
    }

    public SimpleStringProperty getVoterSexProperty() {
        return voterSex;
    }

    public String getVoterPhoneNumber() {
        return voterPhoneNumber.get();
    }

    public SimpleStringProperty voterPhoneNumberProperty() {
        return voterPhoneNumber;
    }

    public void setVoterPhoneNumber(String voterPhoneNumber) {
        this.voterPhoneNumber.set(voterPhoneNumber);
    }

    public String getVoterVoterID() {
        return voterVoterID.get();
    }

    public SimpleStringProperty voterVoterIDProperty() {
        return voterVoterID;
    }

    public void setVoterVoterID(String voterVoterID) {
        this.voterVoterID.set(voterVoterID);
    }

    public String getVoterPassword() {
        return voterPassword.get();
    }

    public SimpleStringProperty voterPasswordProperty() {
        return voterPassword;
    }

    public void setVoterPassword(String voterPassword) {
        this.voterPassword.set(voterPassword);
    }
}
