# Question Formulation Technique (QFT)

Based on **Cultivating a Culture of Entrepreneurship Mindset and Undergraduate Research – CEMUR**<br>
Funded by The National Science Foundation’s Improving Undergraduate STEM Education: Hispanic-Serving Institutions (HSI Program) Award # 1953751<br>

Using resources from [Right Question Institute](https://rightquestion.org/education/resources/)

## QFT Overview

Part 1 of this activity (Question Formulation Technique) will be a group activity to help everyone ask and develop lots of questions that could be answered through the available datasets.

## CURE-E Project Proposal Overview

Part 2 (Project Proposal), along with the Final Project, will be an individual activity. You will confirm which question you are focusing on, determine stakeholders, and find a dataset to work with. If you would like to, you can approach this project with a group mindset -- with everyone aiming to provide insights for a specific stakeholder, but each individual answering a different question for that stakeholder.

## Introduction

The skill of question asking is far too rarely deliberately taught in school. The Question Formulation Technique (QFT) provides a simple yet powerful way to teach students how to formulate, work with, and use their own questions.<br>

You will need to develop a question that your CURE-E Final Project will set out to answer. This semester, you will focus on:

* **Historical weather data**: [publicly available historical weather data](https://www.ncdc.noaa.gov/cdo-web/datasets) for Chico, CA or surrounding communities. This data is provided by the National Oceanic and Atmospheric Administration (NOAA). We can search for and request data using their [Climate Data Online Search](https://www.ncei.noaa.gov/cdo-web/search) tool.

* **Fall 2024 Change**: [Many NCEI systems are unavailable until further notice due to Hurricane Helene's impacts to our NC data center.](https://www.ngdc.noaa.gov/)
  * **Federal Reserve Economic Data**: [Federal Reserve Economic Data (FRED)](https://fred.stlouisfed.org/) (which includes US and international time series data that can be downloaded, graphed, and tracked) is provided by the Federal Reserve Bank of St. Louis. They offer data for the consumer price index, gross domestic product, inflation, the unemployment rate, and much more. If you are not sure what to focus on, I encourage you to look into data related to [unemployment](https://fred.stlouisfed.org/searchresults/?st=unemployment&isTst=1), which can provide valuable insights into labor market trends and economic health.

## Attitude

Entrepreneurial Mindset: Flexible and Adaptable, Creative and Innovative, Initiative and Self Reliance, Communicate and Collaborate, Critical Thinking and Problem Solving, Opportunity Recognition

## Preparation

We will use a shared Google Doc to complete this assignment(link on Canvas).
- Divide yourselves into groups of 3-4 students
- Decide how you will complete this exercise (e.g. Which dataset will you focus on? Who will type the questions? How are you making sure that everyone gets a chance to provide input?)
- List the names of each team member (first and last)<br>

Nowadays, we have access to vast amounts of data, but it can sometimes be difficult to extract useful information from that data. Take a look at the example datasets:

* **Historical weather data**
  * Example datasets:
    * `assets/ChicoUnivFarm-1906-2023.csv` (one station)
    * `assets/chico-weather-2005-2024.csv` (several stations in the region)
    * `assets/butte-weather-2014-2024.csv` (several stations in the region)
    * `assets/sac-airport-1998-2024.csv` (one station)
  * Each row displays the readings from a given day. Columns include station ID, station name, date, and data related to precipitation and air temperature.
  * The [Global Historical Climatology Network Daily Documentation](https://www.ncei.noaa.gov/pub/data/cdo/documentation/GHCND_documentation.pdf) can be used as a reference.

* **Historical economic data**
  * Example datasets:
    * `assets/UNRATE-SeasonallyAdjusted-Sep2024.csv` (Unemployment Rate, seasonally adjusted, percent, monthly)
    * `assets/UNRATE-BachelorDeg-Sep24.csv` (Unemployment Rate for people with a Bachelor's Degree and Higher (25 Yrs. & over), seasonally adjusted, percent, monthly)
    * `assets/AvgWeeksUnemployed-Sep24.csv` (Average Weeks Unemployed, seasonally adjusted, number of weeks, monthly)
    * `assets/StickyPriceCPI-Sep24.csv` (Sticky Price Consumer Price Index less Food and Energy, seasonally adjusted, percent change from a year ago, monthly)
  * Other examples of economic datasets worth exploring:
    * [Initial Claims (ICSA)](https://fred.stlouisfed.org/series/ICSA) - number of initial unemployment claims filed by unemployed individuals
    * [Consumer Price Index for All Urban Consumers: All Items in U.S. City Average (CPIAUCSL)](https://fred.stlouisfed.org/series/CPIAUCSL) - a price index of a basket of goods and services paid by urban consumers (percent changes in the price index measure the inflation rate between any two time periods)
    * [Personal Consumption Expenditures (PCE)](https://fred.stlouisfed.org/series/PCE) - a measure of consumer spending (this data shows the total amount in billions of dollars; it would also be useful to consider how much expenditures are increasing or decreasing between any two time periods)
    * [Gross Domestic Product (GDP)](https://fred.stlouisfed.org/series/GDP) and [Real Gross Domestic Product (GDPC1)](https://fred.stlouisfed.org/series/GDPC1) - GDP is the total value of all goods and services produced in a given time period (a good gauge of consumer purchasing power), while real GDP is adjusted for inflation (a more accurate gauge of the change in production levels from one period to another).
    * [Federal Funds Effective Rate (FEDFUNDS)](https://fred.stlouisfed.org/series/FEDFUNDS) - the interest rate at which depository institutions trade federal funds (balances held at Federal Reserve Banks) with each other overnight (it influences a wide range of market interest rates).
    * [New Privately-Owned Housing Units Started: Total Units (HOUST)](https://fred.stlouisfed.org/series/HOUST) - tracks the number of new housing units being built (good indicator of the health of the housing market and the overall economy).

These datasets are organized, but they may not be organized how you want them to be. Even given sorted data, it can still be challenging to find specific pieces of information, or discover answers to questions that previously had no known solution.<br>

Take a few minutes to individually look at the data and think about different types of insight that could be gained from the data.

* For the historical weather data, consider different stakeholders who could benefit from analysis of climate information -- individuals in agriculture, emergency management, renewable energy, tourism, outdoor recreation, and government agencies -- people like city planners, student club leaders, farmers, gardeners, delivery drivers, event planners, etc.<br>

* For the historical economic data, consider different stakeholders who could benefit from analysis of economic information -- job seekers, consumers, investors, human resource departments, economists, policymakers, and individuals in economic development and other government agencies.<br>

### Developing a Research Question

Below are some examples of good starting questions that could provide interesting insight for specific stakeholders. These questions are meant to give you some inspiration -- you can use a question as is, choose a unique way to approach solving the question, and/or modify the question based on your interests:
#### Example questions: historical weather data
* (Note for all historical weather data: Your approach could look specifically at one station with many years of data available, or you could look at several stations in the area for comparison or to find the averages.)
* **What is the average date for the last Spring frost in the Chico area?**
  * This can help farmers and home gardeners have a better idea of when they can start planting in the Spring without damage to new plants.
  * To answer this question, you might look at the minimum temperatures in specific months (e.g. January - June) and calculate the percentage possibility that temperatures get below 32 degrees F (light freeze) during some range of days.
  * You could modify the question to focus on finding the first Fall frost (e.g. September - December), to give farmers and home gardeners a better idea for when they should harvest their last crops for the growing season.
* **How often can farmers and home gardeners expect temperatures to be above the optimal range for growing tomatoes during the harvest season?**
  * There are ways to protect plants from extreme temperatures; however, it requires planning, and it helps to have an idea of when you can expect extreme temperatures.
  * To answer this question, you might look at the maximum temperatures during the harvest season (roughly June - November) and calculate the average number of days that temperatures get above 85 degrees F (or 90-95F -- max optimal temperature may vary based on factors like humidity).
  * You could modify the question to focus on a different plant (e.g. rice, almonds, grapes, lettuce, peppers, etc) and its specific needs.
* **What is the probability that it will rain during Spring Commencement ceremonies?**
  * Looking at historical weather data can help campus student organizations and event planners schedule outdoor events or make backup plans to ensure better attendance and participant comfort.
  * To answer this question, you might start by looking at the number of days during the month of May (or June) that have precipitation. Then, you can determine the probability of rain occurring on a given day based on the average number of days with precipitation during May over the years 1920-2020.
  * You could modify this question to focus on a different type of extreme weather (e.g. temperatures above 90 degrees Fahrenheit) that could also impact attendance, comfort, and health.
* **Is there a trend in the frequency or intensity of heatwaves in Chico, CA?**
  * Understanding how often heatwaves occur and/or determining if the temperature during those heatwaves is increasing can help public health departments develop action plans and provide guidance for vulnerable populations, such as the elderly, children, or people with pre-existing health conditions.
  * To answer any question focusing on trends, make sure you analyze many years of data (at least 20-30, but ideally more years). It will most likely be impossible to identify a trend for a short period of time (e.g. 5 years).
  * You could modify this question by focusing on either max temperatures above a certain threshold (e.g. 90-100F), or min temperatures above a certain threshold (e.g. 70-75F), as both can cause additional stress on humans (and infrastructure).
* **How does the precipitation this winter compare to historical seasonal precipitation patterns in Butte County?**
  * Identifying how current conditions compare to historical precipitation (or drought) patterns can provide city planners with valuable insight for water resource management, agriculture, and other sectors.
  * For this question, you would want to calculate and summarize data for the current season, but then you would also to compare these results with totals or averages from past seasons. This is another question that requires looking at patterns, so make sure you analyze many years of data (at least 20-30, but ideally more years).
  * You could modify this question by using a specific drought index (e.g. the Standardized Precipitation Index), analyzing average number of occurrences of precipitation during specific months, or focusing on total, average, max/min amounts of precipitation seen during specific months.

#### Example questions: historical economic data
* (Note for all historical economic data: Your project needs to work with at least 2 datasets and at least 1000 entries (about 84 years for monthly data). Your goal is not to create a graph that looks like one already provided by FRED -- rather, you want to see if you can gain any statistical insight into labor market trends and economic health that might not be immediately obvious by looking at a graph).
  * **How does the unemployment rate for individuals who have a bachelor's degree compare with the overall unemployment rate?**
    * You could modify this question to compare the situation for different states/regions, age groups, sex (male/female), race, or other sectors of the population, and examine if the disparities are smaller or greater depending on the time of year.
  * **Are there any seasonal trends or cyclical patterns in unemployment rates over time?**
    * You could modify this question by focusing on unemployment rates that are above a certain threshold, or the length of time that job seekers are unemployed. You may want to identify what a "normal" amount of unemployment is, and identify if there are specific times of year when you can expect unemployment to typically be lower or higher than average.
  * **In which historical periods did the unemployment rate experience the most rapid increases, and how do these periods compare to the overall average monthly change in unemployment?**
    * You could modify this question by focusing on different regional variations or demographic factors (different events may have had a different impact on people in different areas of the country, people in different age groups, or people with different levels of education).
  * **Is there any relationship between unemployment and the Consumer Price Index (an indicator of inflation)?**
    * You could modify this question by focusing on other economic indicators, e.g. does an increase in unemployment associated with a decrease in Gross Domestic Product (GDP)? Even if you are not using formal statistical analysis, you can try to see if there are any patterns in the data.

  * These questions can help policymakers and government officials identify disparities between different sectors of the population, better understand the economic situation of their constituents, forecast labor market needs, and plan for seasonal unemployment benefits. Job seekers, employers, and academic institutions can use these types of information to better understand the market and make more informed decisions.
  * There are several things you should take into consideration for planning your final project (including, but not limited to, the following):
    * Are you going to identify the most current data and compare this data with numbers or averages from past years?
    * Are you going to categorize the data by month or season (and what dates are you considering for each season)?
    * If you are trying to accurately identify patterns, are you making sure you look at many years worth of data?
    * If comparing different types of data, make sure they are on a comparable scale (e.g. change from month to month).
    * Most of the FRED data is very consistent; however, make sure you consider how your program will handle missing data -- will it ignore rows with missing values, or will it attempt to use some default value in place of missing values?

You are not required to use my example questions -- ultimately, I want you to choose something that interests you! However, be aware that some questions may be difficult or impossible to answer with the available datasets. Keep these ideas in mind for things to avoid in choosing your research question:
* In most cases, you CANNOT identify the impact of \<fill in the blank\> -- a question like, "What is the impact of extreme precipitation?" is unanswerable given the information we have available (i.e. historical weather datasets). Instead, you can focus on things like identifying the occurrences/frequency and intensity of weather events, with the goal of helping different entities make decisions based on that data.
* Your question should be somewhat specific -- a question that is too broad will be impossible to answer in a project that you are expected to complete in the amount of time available to you. If you have a bunch of questions floating around in your head, talk to the instructor or your peers to help you refine your question and focus on providing some specific type of insight.
* At the same time, your question should not be too simple. A question like, "What was the maximum temperature in 2023?" (which can be solved with a basic search) has very limited usefulness. Your project should require some calculations and analysis on your part. Your program should be able to print out all entries in a readable format, but it should also go beyond that -- the program should provide some insight, without requiring the user to read through the dataset and make their own analysis.

## Process

Now it is time to start formulating your own questions!<br>

1. Question Focus
  - :heavy_check_mark: Focus on the example dataset, while being aware that your group can choose a different dataset for your CURE-E project (e.g. for a specific station, for a longer date range, etc).
  - :heavy_check_mark: Start with the example questions listed above, and think about other questions you can ask that are related to these questions.
    - **What types of data are you most interested in?** Are there any causes or issues you care about that could be explored with these types of datasets?
      - A list of topics related to economics that at least one member of your group finds intriguing or relevant, that could be addressed with available data. In your list, you can include sectors that interest you (education level, regions/states, or other demographic distinctions), and various perspectives and interests that could benefit from your research. (Who are the potential beneficiaries of your findings?)
    - **What are some questions that could be explored with the economic datasets available?**
      - Consider: **What are some questions that can help you answer the provided example questions?** Consider simple questions that have an easy-to-find answer and can help you build a response to the original question.
      - Or: **What are some questions that can expand beyond the example questions?** These questions may, for instance, be similar questions with a different focus for a different stakeholder. Consider questions that take into account a range of dates (months, years, seasons), several locations, multiple categories (e.g. precipitation and min/max temperature), different statistical calculations (e.g. mean average, range, variance, percentile), etc.
  - :heavy_check_mark: As you formulate questions, think about some potential stakeholders (community members or groups who would benefit from this information). In many cases, your research can be more impactful if it has a specific stakeholder in mind.
2. Produce Your Questions
  - :heavy_check_mark: Follow the rules:
    - a) Ask as many questions as you can
    - b) Do not stop to discuss, judge or answer
    - c) Record exactly as stated
    - d) Change statements into questions
  - :heavy_check_mark: Number your questions
3. Improve Your Questions
  - :heavy_check_mark: Categorize questions as Closed or Open-ended
    - a) Closed-Ended: Narrowly focused questions that can be answered with a simple “yes” or “no”, one word, or a single piece of data. Closed-ended questions are focused on gathering precise answers and targeted facts.
    - b) Open-Ended: Questions that encourage discussion and exploration, often requiring a longer explanation with a more detailed and nuanced response. There may not be a single correct solution; however, research into the question can provide more in-depth understanding, insights, and analysis.
  - :heavy_check_mark: Change questions from one type to another
4. Strategize
  - :heavy_check_mark: Prioritize your questions
  - :heavy_check_mark: Action plan or discuss next steps
  - :heavy_check_mark: Share
5. Reflect
  - :heavy_check_mark: Individual written reflection or small group reflection
  - :heavy_check_mark: Volunteers share out to full group

Reminder: when you start this exercise, you should try to come up with as many questions as you can. By the end of the exercise, your list of questions should identify which questions are closed-ended and which are open-ended, and it should be clear which questions have the highest priority.<br>

## Conclusion

The goal today is to generate ideas for potential questions you can answer through your CURE-E Final Project. In the upcoming weeks, work with your group to determine a stakeholder and decide on at least one question for each group member to focus on. Your question for the Final Project must be sufficiently complex -- try to think of a question that requires factual data but cannot be answered with a simple search (e.g. what day had the hottest temperature?). Check in with the instructor to confirm if your question matches this requirements.<br>

To successfully complete this assignment, each participant should submit an individual project proposal to Canvas that includes the following components:<br>

1. Clearly state the research question you intend to address
2. Identify the stakeholder(s) who stand to gain from the insights derived from your project
3. Provide some details about the dataset you intend to use and the data fields on which you will focus.
  * For historical weather data, you should focus on Daily Summaries. Some variables you should provide here are (1) the Date Range, (2) Station/Zip Code/City or other geographic/location identifier, and (3) observations/values (e.g. precipitation (PRCP), snowfall (SNOW), max temperature (TMAX), min temperature(TMIN), etc).
  * For historical economic data, you may find monthly, daily, or seasonal summaries. You will need to utilize two or more datasets, and your datasets must contain at least 1000 entries combined (for monthly data, this requires at least 84 years, so you could look at two datasets that each have at least 42 years of data, or 3 datasets that have at least 28 years of data).
    * You should provide here: (1) The datasets you plan to use (list the date range (e.g. "Jan 1948 to Sep 2024") and frequency (e.g. "monthly") for each)
4. You may use the same dataset and have the same stakeholder as other students, but you should be writing your own program and individually addressing a unique question. If you are working with other students to provide insights for a specific stakeholder, with each individual answering a different question for that stakeholder, list the names of the other students.<br>


Reminder: this assignment has 2 components -- the QFT discussion (submitted through the shared Google Doc) and the Project Proposal (a PDF or text submission to Canvas).
