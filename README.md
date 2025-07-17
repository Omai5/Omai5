# Prepare the updated README content based on user's latest instructions 
readme_updated_content = """# Hi there, I'm Omar 👋 
 
<div align="center"> 
  <img width="100%" src="assets/banner.png" alt="Omar Abdelrahman Ali - Banner" /> 
</div> 
 
<h3 align="center"> 
  Omar Abdelrahman Ali • Backend Developer 
</h3> 
 
<p align="center"> 
  📧 omai.ali.2005i@gmail.com • 📞 01044111575 
</p> 
 
--- 
 
## 🧰 Tech Stack 
 
### 🖥️ Programming Languages 
<p align="left"> 
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2b%2b&logoColor=white" /> 
  <img src="https://img.shields.io/badge/Rust-000000?style=for-the-badge&logo=rust&logoColor=white" /> 
  <img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white" /> 
  <img src="https://img.shields.io/badge/MySQL-4479A1?style=for-the-badge&logo=mysql&logoColor=white" /> 
  <img src="https://img.shields.io/badge/SQL-CC2927?style=for-the-badge&logo=sqlite&logoColor=white" /> 
  <img src="https://img.shields.io/badge/MongoDB-47A248?style=for-the-badge&logo=mongodb&logoColor=white" /> 
</p> 
 
### ⚙️ Frameworks & Tools 
<p align="left"> 
  <img src="https://img.shields.io/badge/Go-00ADD8?style=for-the-badge&logo=go&logoColor=white" /> 
  <img src="https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white" /> 
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" /> 
  <img src="https://img.shields.io/badge/Postman-FF6C37?style=for-the-badge&logo=postman&logoColor=white" /> 
  <img src="https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white" /> 
  <img src="https://img.shields.io/badge/Visual%20Studio%20Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white" /> 
</p> 
 
--- 
 
## 📊 GitHub Stats 
 
<a href="https://github.com/Omai5"> 
  <img align="center" src="https://api.githubtrends.io/user/svg/Omai5/langs?time_range=one_year&use_percent=True&theme=bright_lights" /> 
</a> 
 
<a href="https://github.com/Omai5"> 
  <img align="center" src="https://github-readme-stats.vercel.app/api?username=Omai5&bg_color=071A2C&icon_color=4194FD&show_icons=true&count_private=true&theme=tokyonight&line_height=27&text_color=FFFFFF" alt="Omar's GitHub Stats"/> 
</a> 
 
--- 
 
## 📬 Contact Me 
 
<div align="center"> 
  <a href="mailto:omai.ali.2005i@gmail.com" target="_blank"> 
    <img src="https://img.shields.io/badge/Gmail-%231877F2.svg?&style=flat-square&logo=gmail&logoColor=white&color=071A2C" alt="Gmail"> 
  </a> 
</div> 
""" 
 
# Overwrite the previous README.md 
with open("/mnt/data/OmarPortfolioREADME/README.md", "w") as f: 
    f.write(readme_updated_content) 
 
# Zip the updated project 
updated_zip_path = "/mnt/data/OmarPortfolioREADME_Updated.zip" 
with zipfile.ZipFile(updated_zip_path, 'w') as zipf: 
    for foldername, subfolders, filenames in os.walk(base_path): 
        for filename in filenames: 
            file_path = os.path.join(foldername, filename) 
            arcname = os.path.relpath(file_path, base_path) 
            zipf.write(file_path, arcname) 
 
updated_zip_path
