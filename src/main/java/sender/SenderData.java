package sender;

public class SenderData {
	private static Logger log = new Logger();

	public static SenderParameters isEmpty(SenderParameters batteryValue) {
		if (batteryValue == null)
			return null;
		return batteryValue;
	}

	public static boolean checkNumeric(String noofEntries) {
		try {
			Integer.parseInt(noofEntries);
		} catch (NumberFormatException e) {
			log.setMessage("Please enter a Valid Input. not a valid one");
			return false;

		}
		return true;
	}

	public static boolean validateDataSize(String noofEntries) {
		if ((Integer.parseInt(noofEntries)) >= 10) {
			return true;
		}
		log.setMessage("Data sent in stream is less that 10 values");
		return false;

	}

}
