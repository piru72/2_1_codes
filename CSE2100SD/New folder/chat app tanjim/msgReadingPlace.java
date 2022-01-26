
// msgReadingPlace is a interface, by using this interface user'll get flexibility from where he want to read message.
// He may read message from his system, or database or cloud too. So this methods implication depends on consumer or server wish
public interface msgReadingPlace {
	public void startReading();
}
