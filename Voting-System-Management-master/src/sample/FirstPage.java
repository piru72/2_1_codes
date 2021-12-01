package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class FirstPage {
    public FirstPage(){

    }
    @FXML
    private Button firstAdminButton;
    @FXML
    private Button voterButton;
    @FXML
    private Button resultButton;

    public void firstAdminSelection(ActionEvent event) throws Exception{
        Main mm=new Main();
        mm.changeScene("admin/adminLogin.fxml");
    }
    public void VoterLogin(ActionEvent event) throws Exception{
//        Main vl=new Main();
//        vl.changeScene("voterLogin.fxml");
    }
    public void firstVoterSection(ActionEvent event) throws Exception{
        Main vl=new Main();
        vl.changeScene("voter/voterLogin.fxml");
    }
    public void firstResultSelection(ActionEvent event) throws Exception{
        Main rs=new Main();
        rs.changeScene("result/result.fxml");
    }
}
