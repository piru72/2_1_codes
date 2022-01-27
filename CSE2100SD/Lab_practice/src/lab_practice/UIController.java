/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_practice;

import java.io.BufferedReader;
import java.io.FileReader;
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
import javafx.scene.control.Button;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

/**
 * FXML Controller class
 *
 * @author parve
 */
public class UIController implements Initializable {

    @FXML
    private TextField username;
    @FXML
    private PasswordField Password;
    @FXML
    private Button login_button;

    /**
     * Initializes the controller class.
     */
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }

    @FXML
    private void LoginAction(ActionEvent event) throws IOException {
        System.out.println("Hello world");

        String username_defined = "";
        String password_defined = "";

        String u = username.getText();
        String p = Password.getText();

        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));

        while ((username_defined = reader.readLine()) != null) {
            password_defined = reader.readLine();
            
            if (username_defined.equals(u) && password_defined.equals(p)) {
                FXMLLoader loader = new FXMLLoader(getClass().getResource("welcome_page_ui.fxml"));
                Parent root = loader.load();
                System.out.println("Hello world_2");
                Scene scene = new Scene(root);

                Welcome_page_uiController welcome = loader.getController();

                welcome.setMsg(u);

                Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
                stage.setScene(scene);
                stage.setTitle("Welcome Page");
                stage.show();

            }
        }

        reader.close();
    }

}
