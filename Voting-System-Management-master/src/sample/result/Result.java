package sample.result;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import sample.Main;
import sample.voter.VoterPanel;

public class Result {
    public Result(){

    }
    @FXML
    private Button resultLogoutButton;
    @FXML
    private Button seeResultButton;
    @FXML
    private Label winner;
    @FXML
    private Label hathiVote;
    @FXML
    private Label ghoraVote;

//    public void getWinner() {
//        VoterPanel gw=new VoterPanel();
//        if(gw.voteCountForRepublican>gw.voteCountForDemocrat){
//             winner.setText("Republicans are the winner");
//        }
//        else if (gw.voteCountForDemocrat>gw.voteCountForRepublican){
//            winner.setText("Democrtes are the winner");
//        }
//        else {
//            winner.setText("both gets same vote");
//        }
//    }


    public Label getWinner() {
        return winner;
    }

    public Label getGhoraVote() {
        return ghoraVote;
    }

    public Label getHathiVote() {
        return hathiVote;
    }

    public void resultLogout(ActionEvent event) throws Exception{
        Main rlo= new Main();
        rlo.changeScene("firstPage.fxml");
    }

    public void seeResult(ActionEvent event) throws Exception{
        seeResult();
    }
    public void seeResult() throws Exception{
        VoterPanel gw=new VoterPanel();
        // Result sr=new Result();
        if (gw.voteCountForRepublican>gw.voteCountForDemocrat){
            getWinner().setText("Republican's are the winner");
        }
        else if (gw.voteCountForDemocrat>gw.voteCountForRepublican){
            getWinner().setText("Democrat's are the winner");
        }
        else {
            getWinner().setText("no winner.same votes");
        }

        getGhoraVote().setText(gw.toString());
        getHathiVote().setText(gw.toStringForRepublic());


    }

    @Override
    public String toString() {
        return "Result{" +
                "winner=" + winner +
                '}';
    }
}