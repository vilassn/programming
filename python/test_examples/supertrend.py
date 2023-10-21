import talib
import pandas as pd

def calculate_supertrend(data, period=7, multiplier=3.0):
    high = data['High'].values
    low = data['Low'].values
    close = data['Close'].values

    # Calculate the ATR (Average True Range) using ta-lib
    atr = talib.ATR(high, low, close, timeperiod=period)

    # Calculate the basic upper and lower bands
    basic_upper_band = (high + low) / 2 + multiplier * atr
    basic_lower_band = (high + low) / 2 - multiplier * atr

    # Initialize supertrend series with NaN values
    supertrend = [float('nan')] * period

    # Calculate Supertrend values
    for i in range(period, len(data)):
        if close[i - 1] <= basic_upper_band[i - 1]:
            supertrend.append(max(basic_upper_band[i], close[i - 1]))
        else:
            supertrend.append(min(basic_lower_band[i], close[i - 1]))

    data['Supertrend'] = supertrend

    return data

# Example usage:
if __name__ == "__main__":
    # Assuming you have OHLC data (Open, High, Low, Close) in a pandas DataFrame
    # Here, we're creating a simple DataFrame for demonstration purposes
    data = pd.DataFrame({
        'Date': pd.date_range(start='2023-01-01', periods=100),
        'Open': [100 + i for i in range(100)],
        'High': [110 + i for i in range(100)],
        'Low': [90 + i for i in range(100)],
        'Close': [105 + i for i in range(100)],
    })

    # Calculate Supertrend with default parameters (period=7, multiplier=3.0)
    data = calculate_supertrend(data)

    print(data[['Date', 'Supertrend']])
