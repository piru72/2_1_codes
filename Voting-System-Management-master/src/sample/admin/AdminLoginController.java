package sample.admin;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import sample.Main;


public class AdminLoginController {

    public AdminLoginController(){

    }
    @FXML
    private Button adminButton;
    @FXML
    private Label wrongId;
    @FXML
    private TextField adminUsername;
    @FXML
    private PasswordField adminPassword;

    public void adminLogin(ActionEvent event) throws Exception{
        checkLogin();
    }
    public void checkLogin() throws Exception {
        Main m=new Main();

        if (adminUsername.getText().toString().equals("Election Commission") && adminPassword.getText().toString().equals("1234")){
            wrongId.setText("success");
            m.changeScene("admin/adminPanel.fxml");
        }
        else if (adminUsername.getText().isEmpty()&& adminPassword.getText().isEmpty()){
            wrongId.setText("Please enter your username and password to login");
        }
        else {
            wrongId.setText("Wrong username or password");
        }

    }

}
