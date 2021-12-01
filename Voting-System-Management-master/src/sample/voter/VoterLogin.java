package sample.voter;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import sample.Main;
import sample.Person;

public class VoterLogin {
    public VoterLogin(){

    }
    @FXML
    private Button voterLoginButton;
    @FXML
    private TextField voterUsername;
    @FXML
    private PasswordField voterPassword;
    @FXML
    private Label voterLabel;


    public void voterPanel(ActionEvent event) throws Exception{

    }
    public void voterPanelWork(ActionEvent event) throws Exception{
        checkvoterlogin();
    }
    public void checkvoterlogin() throws Exception{
        Main vl=new Main();
        if ((voterUsername.getText().toString().equals("185") && voterPassword.getText().toString().equals("1234"))){
            voterLabel.setText("success");
            vl.changeScene("voter/voterPanel.fxml");
        }
        else if (voterUsername.getText().toString().equals("187") && voterPassword.getText().toString().equals("1234")){
            vl.changeScene("voter/voterPanel.fxml");
        }
        else if (voterUsername.getText().toString().equals("186") && voterPassword.getText().toString().equals("1234")){
            vl.changeScene("voter/voterPanel.fxml");
        }
        else if (voterUsername.getText().toString().equals("188") && voterPassword.getText().toString().equals("1234")){
            vl.changeScene("voter/voterPanel.fxml");
        }
        else if (voterUsername.getText().toString().equals("189") && voterPassword.getText().toString().equals("1234")){
            vl.changeScene("voter/voterPanel.fxml");
        }
        else {

            voterLabel.setText("Please Enter Right Username or Password");
        }

    }
/*public void checkvoterlogin() throws Exception{
    Main vl=new Main();
    if (voterUsername.getText().toString().equals(getVoterVoterID) && voterPassword.getText().toString().equals(getVoterPassword())){
        voterLabel.setText("success");
        vl.changeScene("voter/voterPanel.fxml");
    }
    else {
        voterLabel.setText("Please Enter Right Username or Password");
    }

}*/

}
