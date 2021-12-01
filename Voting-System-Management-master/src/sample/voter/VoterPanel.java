package sample.voter;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import sample.Main;


public class VoterPanel {
    public VoterPanel(){

    }
    public static int voteCountForDemocrat=0;
    public static int voteCountForRepublican=0;
    @FXML
    private CheckBox republicanPartyBox;

    @FXML
    private CheckBox democraticPartyBox;

    @FXML
    private Button voterLogOut;
    @FXML
    private Button casteVote;

    public void logOut(ActionEvent event) throws Exception{
        Main lo=new Main();
        lo.changeScene("firstPage.fxml");
    }
    public void casteVote(ActionEvent event)throws Exception{
        countVote();
    }
    public void countVote() throws Exception{
        if (republicanPartyBox.isSelected()){
            voteCountForRepublican++;
        }
        else if (democraticPartyBox.isSelected()){
            voteCountForDemocrat++;
        }
    }

    @FXML
    private void handleRepublicanParty(){
        if(republicanPartyBox.isSelected()){
            democraticPartyBox.setSelected(false);
            // voteCountForRepublican++;
        }
    }
    @FXML
    private void handleDemocraticParty(){
        if (democraticPartyBox.isSelected()){
            republicanPartyBox.setSelected(false);
            //voteCountForDemocrat++;
        }
    }

    public static int getVoteCountForDemocrat() {
        return voteCountForDemocrat;
    }

    public static int getVoteCountForRepublican() {
        return voteCountForRepublican;
    }

    @Override
    public String toString() {
        return ""+getVoteCountForDemocrat();
    }

    public String toStringForRepublic(){
        return ""+getVoteCountForRepublican();
    }
}