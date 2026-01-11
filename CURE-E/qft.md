# Question Formulation Technique (QFT) and CURE-E Project Proposal

Based on **Cultivating a Culture of Entrepreneurship Mindset and Undergraduate Research – CEMUR**<br>
Funded by The National Science Foundation’s Improving Undergraduate STEM Education: Hispanic-Serving Institutions (HSI Program) Award # 1953751<br>

Using resources from [Right Question Institute](https://rightquestion.org/education/resources/)

## QFT Overview

Part 1 of this activity (Question Formulation Technique) will be a group activity to help everyone ask and develop lots of questions that could be answered through the available datasets.

How much experience do you have using [scientific practices](https://undsci.berkeley.edu/lessons/pdfs/complex_flow_handout.pdf)?

## CURE-E Project Proposal Overview

Part 2 (Project Proposal), along with the Final Project, will be an individual activity. You will confirm which question you are focusing on, determine stakeholders, and find a dataset to work with. If you would like to, you can approach this project with a group mindset -- with everyone aiming to provide insights for a specific stakeholder, but each individual answering a different question for that stakeholder.

## Introduction

The skill of question asking is far too rarely deliberately taught in school. The Question Formulation Technique (QFT) provides a simple yet powerful way to teach students how to formulate, work with, and use their own questions.<br>

You will need to develop a question that your CURE-E Final Project will set out to answer. This semester, you will focus on:

* **Flight Delay Data**: [publicly available data on flight arrivals and delays at U.S. airports](https://www.kaggle.com/datasets/sriharshaeedala/airline-delay). This data is accessible through [Kaggle](https://www.kaggle.com/), with the data originally obtained from the Bureau of Transportation Statistics Airline Service Quality Performance 234 and licensed through [U.S. Government Works](https://www.usa.gov/government-copyright). The Bureau of Transportation Statistics provides more information for [Understanding the Reporting of Causes of Flight Delays and Cancellations](https://www.bts.gov/topics/airlines-and-airports/understanding-reporting-causes-flight-delays-and-cancellations).
  * [Descriptions of the flight delay column headings](https://www.openintro.org/data/index.php?data=airline_delay)

## Attitude

Entrepreneurial Mindset: Flexible and Adaptable, Creative and Innovative, Initiative and Self Reliance, Communicate and Collaborate, Critical Thinking and Problem Solving, Opportunity Recognition

## Preparation

We will use a shared Google Doc to complete this assignment(link on Canvas).
- Divide yourselves into groups of 3-4 students
- Decide how you will complete this exercise (e.g. Who will type the questions? How are you making sure that everyone gets a chance to provide input?)
- List the names of each team member (first and last)<br>

Nowadays, we have access to vast amounts of data, but it can sometimes be difficult to extract useful information from that data. Take a look at the provided dataset:

* `assets/Airline_Delay_Cause.csv`
  * Each row displays airline arrival and delay data for U.S. airports, categorized by carrier, in a specific year and month (August 2013 - August 2023).
  * Columns include information for the date, carrier, airport, number of arriving flights, number of total delays, number of delays for specific causes (due to air carrier, weather, National Aviation System, security breach), and total time (in minutes) for delays due to each cause.
  * The [structure of the dataset](https://www.kaggle.com/datasets/sriharshaeedala/airline-delay/data) is described in the **About Dataset** section; these [descriptions of the flight delay column headings](https://www.openintro.org/data/index.php?data=airline_delay) can also be used as a reference.

The dataset is organized, but it may not be organized how you want it to be. Even given sorted data, it can still be challenging to find specific pieces of information, or discover answers to questions that previously had no known solution.<br>

Take a few minutes to individually look at the data and think about different types of insight that could be gained from the data. As mentioned in the **About Dataset** section, the data can be used for variety of purposes to inform decision-making processes, improve operational strategies, and contribute to a more efficient and reliable air travel experience. Potential options for exploration include but are not limited to:

* Performance Analysis: Assess the on-time performance of different carriers
  at specific airports and identify potential areas for improvement.

* Trend Identification: Analyze temporal trends in delays, cancellations, and
  diversions to understand whether certain months or periods exhibit higher operational challenges.

* Root Cause Analysis: Investigate the primary contributors to delays, such as
  carrier-related issues, weather conditions, NAS inefficiencies, security
  concerns, or late aircraft arrivals.

* Benchmarking: Compare the performance of various carriers across different
  airports to identify industry leaders and areas requiring attention.

* Predictive Modeling: Use historical data to develop predictive models for
  flight delays, aiding in the development of strategies to mitigate
  disruptions.

* Industry Insights: Contribute to a broader understanding of the factors
  influencing operational efficiency within the U.S. aviation sector.


### Developing a Research Question

Below are some examples of good starting questions that could provide interesting insight for specific stakeholders. These questions are meant to give you some inspiration -- you can use a question as is, choose a unique way to approach solving the question, and/or modify the question based on your interests:

#### Example questions: Flight Delay Data

Note: the entire dataset is very large -- I would recommend focusing on a few specific variables (you do not need to work with all of the columns). You can also focus on specific rows (e.g. one or more specific carriers or airlines)

* Example of a question that analyzes performance:
  * **Among flights at <specific airports>, which carrier has the lowest percentage of arrivals delayed by 15 minutes or more?**
  * This can help airport operations managers in deciding which carriers to allocate gates to, as well as passengers who may be choosing airlines based on their reliability at a specific airport.
  * Examples of ways you could modify this question include focusing on large airports only (e.g. those with >= N number of flights arriving at the airport) or adjusting the metric (e.g. percentage of delayed flights, average delayed minutes per flight)
* Example of a question that identifies a trend:
  * **Across all years, which month has the highest average delay minutes per flight due to <specific cause> in <specific region>?**
  * This can help airlines make seasonal adjustments to their schedules and air traffic control plan staffing levels.
  * Examples of ways you could modify this question include comparing two specific causes side by side, comparing one airport vs all other airports, or comparing the most recent year with the previous year(s).
* Example of a question that identifies a root cause:
  * **For <specific carrier>, which delay category occurs most frequently across all flights?**
  * This can help airline operations leadership decide where to invest improvements and maintenance teams address carrier-related delays.
  * Examples of ways you could modify this question include doing a per-airport or per-month breakdown for your chosen carrier, or adjusting the metric to track delay categories by the number of minutes delayed by each.
* Example of a question that does some benchmarking:
  * **At how many shared airports does <carrier A> have lower average delay minutes due to <specific cause> than <carrier B>?**
  * This can help airports choose preferred airline partnerships and travel management companies advise clients.
  * Examples of ways you could modify this question include counting airports where <carrier A> performs better than <carrier B>, identifying airports with the largest performance gap, or comparing across multiple causes.
* Example of a predictive modeling question:
  * **How has the total number of flight cancellations changed from year to year between 2013 and 2023?**
  * This can help passengers understand reliability trends and investors identify long-term risks.
  * Examples of ways you could modify this question include identifying the largest single-year change or filtering for specific carriers or airports.
* Example of an industry insights question:
  * **Which delay category accounts for the largest proportion of total delay minutes across all flights in the dataset?**
  * This can help the airline industry collectively identify systemic bottlenecks and plan improvement initiatives.
  * Examples of ways you could modify this question include adjusting the scope (specific carrier, airport, year, or month), or comparing small airports vs large airports (determined by number of arrivals).<br>

In general, you will want to store some identifying information (carrier, airport, date) as well as key variables based on your question (e.g. if you are focusing on total number of arrivals and total number of delays of 15 minutes or more, you do not need the categories for each type of delay, or the categories for total minutes of delay). Conversely, if you are focusing on which delay categories occur most frequently across all flights, you should include all of the delay categories (but may not need the total count or minute-delay variables).<br>

In each case, you will need to:
* handle the input, making sure you get the input you need and organizing it appropriately
* add the data to your data structure (potentially ordering it in a way that is conducive to your task)
* use techniques like traversal, filtering by a key, searching, matching, finding min or max values, computing (sum, average, percentages), etc.

Remember that your real-world question should be something that is answerable with the data you have available.

#### Restrictions

You are not required to use my example questions -- ultimately, I want you to choose something that interests you! However, be aware that some questions may be difficult or impossible to answer with the available datasets. Keep these ideas in mind for things to avoid in choosing your research question:
* In most cases, you CANNOT identify the impact of \<fill in the blank\> -- a question like, "What is the impact of flight delays due to security issues?" is unanswerable given the information we have available. Instead, you can focus on things like identifying occurrences, frequency, patterns, etc with the goal of helping different entities make decisions based on that data.
* Your question should be somewhat specific -- a question that is too broad will be impossible to answer in a project that you are expected to complete in the amount of time available to you. If you have a bunch of questions floating around in your head, talk to the instructor or your peers to help you refine your question and focus on providing some specific type of insight.
* At the same time, your question should not be too simple. A question that can be solved with a very basic search (e.g. the single largest total number of flights delayed due to weather) has limited usefulness as it may be identifying an outlier. Your project should require some calculations and analysis on your part. Your program should be able to print out all entries in a readable format, but it should also go beyond that -- the program should provide some insight, without requiring the user to read through the dataset and make their own analysis.

## Process

Now it is time to start formulating your own questions!<br>

1. Question Focus
  - :heavy_check_mark: Focus on the example dataset
  - :heavy_check_mark: Questions must be answerable using only the dataset
  - :heavy_check_mark: You must be able to use algorithms, data structures, and explicit metrics to answer the question
  - :heavy_check_mark: Start with the example questions listed above, and think about other questions you can ask that are related to these questions.
  - Within the given constraints, write down:
    - What data interests you? Consider specific carriers, airports, regions, types of delays, etc
    - What type of question interests you? Performance measuring, comparisons, identifying trends, etc
    - What stakeholders or groups of people do you care about who might be impacted by flight delays? In many cases, your research can be more impactful if it has a specific stakeholder in mind.
2. Produce Your Questions
  - :heavy_check_mark: Follow the rules:
    - a) Ask as many questions as you can
    - b) Do not stop to discuss, judge or answer
    - c) Record exactly as stated
    - d) Change statements into questions
  - :heavy_check_mark: Number your questions
  - Some things to think about as you're generating questions:
    - Feel free to start with the questions listed above, but add some variation or specifics to make it your own.
    - You may have a hypothesis about a question but want to confirm if your expectations are correct, you may want to uncover inefficiencies, or you may just be curious and wanting to find something unexpected.
    - Consider who might care about the data, and what information they would want from it.
    - No question is too vague or too specific right now - the goal is just to get you thinking. We can refine the questions later.
3. Categorize Your Questions
  - :heavy_check_mark: Categorize questions as Closed or Open-ended
    - a) Closed: Narrowly focused questions that can be answered with a simple “yes” or “no”, one word, or a single piece of data. Closed-ended questions are focused on gathering precise answers and targeted facts.
      - Closed Example: "Which carrier has the most delays?"
    - b) Open: Questions that require interpretation or reframing, often requiring a longer explanation with a more detailed and nuanced response.
      - Open Example: Why is weather such a big problem?
  - :heavy_check_mark: See if you can change questions from one type to another
4. Improve Your Questions
  - Translate your questions into computable forms.
  - Example:
    - Say your original question was, "Which carrier is the worst?"
    - You can improve your question and make it more operational by changing it to something like this, "Which carrier has the highest average arrival delay per flight across all airports?"
  - If you cannot translate all of your questions into a computable form, that is OK; just try to update as many of them as you can.
  - In your questions, make sure to include specifics like a unit of measurement, a time window, and aggregation methods (sum, average (mean), count, minimum/maximum, etc).
5. Strategize
  - :heavy_check_mark: Prioritize your questions
    - Prioritize based on this criteria:
      - Can it be answered using only this dataset?
      - Can the result be computed in a reasonable time?
      - Does it require grouping, searching, or aggregation?
      - Can you explain the result to a stakeholder?
      - Is it something that would matter to a stakeholder?
  - :heavy_check_mark: Action plan or discuss next steps
  - :heavy_check_mark: Share
6. Reflect
  - :heavy_check_mark: Individual written reflection or small group reflection
    - Select at least 1 primary question and at least 1 backup question.
    - You are not tied to the questions brainstormed in class - you may use a question you think up later.
  - :heavy_check_mark: Volunteers share out to full group

Reminder: when you start this exercise, you should try to come up with as many questions as you can. By the end of the exercise, your list of questions should identify which questions are closed-ended and which are open-ended, and it should be clear which questions have the highest priority.<br>

## Conclusion

The goal today is to generate ideas for potential questions you can answer through your CURE-E Final Project. In the upcoming weeks, work with your group or individually to determine a stakeholder and decide on at least one question for each individual to focus on. Your question for the Final Project must be sufficiently complex -- try to think of a question that requires factual data but cannot be answered with a simple search. Check in with the instructor to confirm if your question matches this requirements.<br>

To successfully complete this assignment, each participant should submit an individual project proposal to Canvas that includes the following components:<br>

1. Clearly state the research question you intend to address
2. Identify the stakeholder(s) who stand to gain from the insights derived from your project
3. Provide some details about your plan, the dataset you intend to use, and the data fields on which you will focus.
  * What data structure(s) will you use? Remember that you must implement your own primary data structure; you may not rely solely on standard library containers (e.g. std::map, std::vector)
  * What variables (column headers) will you focus on? Make sure to include some identifiers (e.g. carrier, airport, year, month) as well as the data field(s) you will be working with.
  * What keys are you planning on grouping or searching by?
  * What metrics must be computed?
  * Are there any assumptions or limitations that exist? If so, briefly describe them here.
4. You may use the same dataset and have the same stakeholder as other students, but you should be writing your own program and individually addressing a unique question. If you are working with other students to provide insights for a specific stakeholder, with each individual answering a different question for that stakeholder, list the names of the other students.<br>


Reminder: this assignment has 2 components -- the QFT discussion (submitted through the shared Google Doc) and the Project Proposal (a PDF or text submission to Canvas).
