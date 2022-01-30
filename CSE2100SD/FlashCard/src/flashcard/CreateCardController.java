/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package flashcard;

import java.io.IOException;
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

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

    @FXML
    void exitAction(ActionEvent event) {
        System.out.println("Hello");

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
            stage.setTitle("Welcome Page");
            stage.show();

        } catch (Exception e) {
            //TODO: handle exception
        }

    }

    @FXML
    void playAction(ActionEvent event) {
        System.out.println("Hello");
    }

}
