//Keep https://script.google.com/macros/s/AKfycbzw9fqFBeFbPcfywAFdShe7FsAbR--skPTHFd-XftdyzRjvifZLLFmAI3Ux-k1_VUs9GQ/exec

const script =
  "https://script.google.com/macros/s/AKfycbzw9fqFBeFbPcfywAFdShe7FsAbR--skPTHFd-XftdyzRjvifZLLFmAI3Ux-k1_VUs9GQ/exec";
const form = document.forms["submit-form"];
var info = document.getElementById("info");

form.addEventListener("submit", (e) => {
  e.preventDefault();
  fetch(script, { method: "POST", body: new FormData(form) })
    .then(() => {
      info.innerHTML = "Message Sent Successfully";
      setTimeout(() => {
        info.innerHTML = "";
      }, 5000);
      form.reset();
    })
    .catch(() => {
      info.innerHTML = "Error To Send The Message!";
      setTimeout(() => {
        info.innerHTML = "";
      }, 5000);
    });
});
