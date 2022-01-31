/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package flashcard;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author parve
 */
public class CreateCardController implements Initializable {

    /**
     * Initializes the controller class.
     */
    @FXML
    private Button playButton;

    @FXML
    private Button homeButton;

    @FXML
    private Button exitButton;

    private AnchorPane scenePane;
    Stage stage;

    @FXML
    private Button nextButton;

    @FXML
    private Button saveButton;

    @FXML
    private TextField answerField;

    @FXML
    private TextField questionField;

    @FXML
    private Label question;

    @FXML
    private Label answer;

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

    @FXML
    void exitAction(ActionEvent event) {

        try {
            stage = (Stage) exitButton.getScene().getWindow();
            stage.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @FXML
    void homeaction(ActionEvent event) throws IOException {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("FlashCard.fxml"));
            Parent root = loader.load();

            Scene scene = new Scene(root);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            stage.setScene(scene);
            stage.setTitle("Flash Card");
            stage.show();

        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @FXML
    void playAction(ActionEvent event) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("playCard.fxml"));
            Parent root = loader.load();

            Scene scene = new Scene(root);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            stage.setScene(scene);
            stage.setTitle("Play Flash Card");
            stage.show();

        } catch (Exception e) {

        }
    }

    @FXML
    void saveAction(ActionEvent event) {
        // System.out.println("Action working");

    }

    @FXML
    void nextAction(ActionEvent event) {
        //System.out.println("Action working");
    }

    @FXML
    void questionAction(ActionEvent event) {

        try {
            File myObj = new File("card_1.txt");
            if (myObj.createNewFile()) {
                //System.out.println("File created: " + myObj.getName());
                Writer myWriter = new BufferedWriter(new FileWriter("Card_1.txt", true));

                String question = questionField.getText();
                myWriter.append(question + "\n");
                questionField.setText("");
                myWriter.close();

            } else {
                //System.out.println("File already exists.");
                Writer myWriter = new BufferedWriter(new FileWriter("Card_1.txt", true));

                String question = questionField.getText();
                myWriter.append(question + "\n");
                questionField.setText("");
                myWriter.close();

            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    @FXML
    void answerAction(ActionEvent event) {
        try {
            File myObj = new File("card_2.txt");
            if (myObj.createNewFile()) {
                //System.out.println("File created: " + myObj.getName());
                Writer myWriter = new BufferedWriter(new FileWriter("Card_1.txt", true));

                String answer = answerField.getText();
                myWriter.append(answer + "\n");
                questionField.setText("");
                myWriter.close();

            } else {
                //System.out.println("File already exists.");
                Writer myWriter = new BufferedWriter(new FileWriter("Card_1.txt", true));

                String answer = answerField.getText();
                myWriter.append(answer + "\n");
                answerField.setText("");
                myWriter.close();

            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

}
