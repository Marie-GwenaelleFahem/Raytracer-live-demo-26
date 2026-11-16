# Discovery report

**Project:** Ray tracer for a Los Angeles film studio
**Author:** Marie-Gwenaëlle
**Date:** 16 November 2026

## Problem statement

A Los Angeles film studio needs a ray tracer that its own developers and its partner studios can understand, fix and extend for years, because its current rendering tools produce errors that nobody can explain or fix quickly, but today's options are either generated code that no one can maintain or commercial products that the studio cannot change.

## Client interview summary

**Date:** 16 November 2026
**Format:** semi-structured interview, whole class, round robin, 1 hour.

The questions were asked orally and I did not write them down during the interview. I reconstructed them from memory after the interview, so their wording is approximate. The answers come from my notes. Quotation marks show the client's exact words. Where I do not remember the question, it is marked *not recorded*.

### Questions and answers

| ID | Question (reconstructed from memory) | Answer (from my notes) |
|---|---|---|
| Q1 | What problems do you have with your current tool? | Six months ago, on a big project, they found black dots and artifacts in their images. They did not know why, and the cause has still not been found. They bought an expensive professional licence. It was delivered three weeks later and did not meet all their needs. |
| Q2 | What is a reasonable time to render one image? | "Not too long." |
| Q3 | What do you want to anticipate in the future with our ray tracer? | A reliable image. If there is an anomaly, they want to be able to fix it the same day. |
| Q4 | What hardware do you use for this project? | Designers use a powerful desktop machine to see their work, and expect a smaller image. Production uses larger machines with no graphics cards: rendering is CPU only. |
| Q5 | Which kind of render do you prefer for designers, and for the final production? | Designers need a fast image. For the final render, a high-quality image is preferred. |
| Q6 | How many machines do you use? | 200 machines, and 2 months for the final rendering. |
| Q7 | What length, image quality and number of frames do you expect? | A 90-minute feature film in HD (1080p) at 24 FPS. |
| Q8 | What should our ray tracer do when a designer uses it? *(uncertain)* | It is a black box: objects go in and an image comes out. |
| Q9 | What more can our ray tracer bring you? | The ability to add specific features that Maya does not currently allow. |
| Q10 | What are your long-term goals? | A maintainable solution, open source. |
| Q11 | Apart from using it, what will your partners be able to do with the ray tracer? | Fix bugs and propose changes. |
| Q12 | What will your company do once the ray tracer is finished? | Their dev team of 5 people will use it, integrate it into their own tools and share it with their partners. |
| Q13 | What kind of animation do you make? | Animation similar to Toy Story. |
| Q14 | What is the deadline for this project? | 5 January. The ray tracer must be finished so the team can start work on the production. |
| Q15 | What is the budget for this project? | €500,000 is the total price of the ray tracer. A quarter of it is for the dev team. |
| Q16 | What should we have asked you that we didn't? | What happens when somebody leaves the team: they need to be able to maintain the ray tracer without that person. |
| N1 | *Not recorded* | "Render fears" (my note is unclear). |
| N2 | *Not recorded* | No user interface is required. |
| N3 | *Not recorded* | 10 pre-renders per image. |
| N4 | *Not recorded* | The studio uses Maya, and our ray tracer must integrate with Maya. |

### Findings by theme

Each point shows what the client said, with its source. My own conclusions are marked **Conclusion**.

#### Users and how the ray tracer is used

- There are two uses: designers preview their work on powerful desktop machines, and the final images are rendered on production machines. *(Q4, Q5)*
- The client's dev team (5 people) will integrate the ray tracer into their own tools. *(Q12)*
- No user interface is required. *(N2)*
- The ray tracer is a black box: it takes objects as input and produces an image. *(Q8)*
- The studio uses Maya, and the ray tracer must integrate with it. *(N4)*
- **Conclusion:** the main users of our code are developers, not artists. The input format and the way the ray tracer is called from other tools matter more than a graphical interface.

#### What goes wrong today

- Black dots and artifacts appeared six months ago, and the cause was never found. *(Q1)*
- A commercial licence was bought, but it arrived three weeks later and did not meet all their needs. *(Q1)*
- **Conclusion:** buying an existing product did not solve the problem. This may explain why the client wants its own ray tracer.

#### Performance

- 90-minute film, 1080p, 24 FPS. *(Q7)*
- 200 machines, 2 months for the final rendering. *(Q6)*
- 10 pre-renders per image. *(N3)*
- Designers need a fast image; the final render must be high quality. *(Q5)*
- The acceptable time per image is "not too long". *(Q2)*
- **Conclusion:** 90 min × 60 s × 24 FPS = 129,600 frames. If 2 months means about 60 days, with all 200 machines working 24 hours a day, that gives 288,000 machine-hours. This is about **2 h 13 min per frame** on one machine, if the 2 months are only for the final frames. If the 10 pre-renders are in the same 2 months, it is about **12 min per render** (11 renders per frame).

#### Reliability and diagnostics

- If there is an anomaly in an image, it must be fixed the same day. *(Q3)*
- The cause of the last artifacts was never found. *(Q1)*
- **Conclusion:** the ray tracer must make problems easy to find, not only avoid them. Tests and diagnostic tools are part of the need.

#### Maintainability, extensibility and open source

- The solution must be maintainable and open source. *(Q10)*
- The client wants to add specific features that Maya does not allow. *(Q9)*
- Partner studios will fix bugs and propose changes. *(Q11)*
- The team must be able to maintain the ray tracer when somebody leaves. *(Q16)*
- **Conclusion:** the code must be understandable by people who did not write it. This points to documentation, clear contribution rules and code reviews.

#### Image quality

- The animation style is similar to Toy Story. *(Q13)*
- Fast preview for designers, high quality for the final render. *(Q5)*

#### Constraints

- Deadline: the ray tracer must be finished on 5 January. *(Q14)*
- Budget: €500,000 for the ray tracer, a quarter for the dev team. *(Q15)* **Conclusion:** about €125,000 for the dev team.
- Production machines have no graphics cards: rendering is CPU only. *(Q4)*
- Resolution: 1080p. *(Q7)*
- Integration with Maya, the studio's 3D software. *(N4)*
- Language: C++ (from the problem statement, not from the interview).

### Open questions

- **Time per frame:** "not too long" is not measurable. What is the maximum time for one designer preview, and for one final frame? *(Q2)*
- **Pre-renders:** what is a pre-render, where does it run, and is it part of the 2 months? *(N3, Q6)*
- **Input and Maya:** what "objects" go into the black box, and in which file format? Does the ray tracer run as a plugin inside Maya, or does it read scenes exported from Maya? *(Q8, N4)*
- **Designer preview:** what resolution and time does a designer expect? *(Q4, Q5)*
- **"Finished" on 5 January:** which features must be ready on that date? *(Q14)*
- **"Render fears":** my note is unclear; to check with the class notes. *(N1)*
- **Toy Story style:** which visual effects does this style need for the client? *(Q13)*
- **Budget:** what does the €500,000 pay for, apart from the dev team (machines, licences, support)? *(Q15)*
- **Same-day fix:** who must be able to fix an anomaly the same day, the client's team or ours? *(Q3)*
- **Open source:** under which licence, and who decides which partner changes are accepted? *(Q10, Q11)*

### Possible contradiction

- The client wants a ray tracer that can render a whole film and be maintained for years *(problem statement, Q10)*, but it must be finished by 5 January *(Q14)*, about seven weeks after the interview. It would be useful to ask what "finished" means and what can come later.

## State of the art

Prices were checked on 16 November 2026. "Free" means that the software costs nothing; it does not mean that using it costs nothing (integration, training, maintenance).

### Commercial solutions

| Solution | Maker | Licence | Pricing (date checked) | Capabilities | Sources |
|---|---|---|---|---|---|
| RenderMan 27 | Pixar Animation Studios | Proprietary. Free Non-Commercial version for students, independent artists and researchers | $595 per licence, plus $250 per licence per year for maintenance. Rental: $5 per licence per day (minimum 10 licences for 7 days). (16 Nov 2026) | Production renderer used by Pixar on its own films. One licence works either for an artist seat or for batch rendering. Includes Tractor, Pixar's render farm manager. New development focuses on the XPU engine. | [RenderMan store](https://renderman.pixar.com/store/), [RenderMan FAQ](https://renderman.pixar.com/general-faq) |
| Arnold | Autodesk | Proprietary, subscription. Pay-as-you-go option (Autodesk Flex) | The official page did not display a price on 16 Nov 2026. Third-party listings show $430 per year for a single-user subscription. Multi-user subscriptions are sold through resellers. | Monte Carlo ray tracer. CPU and GPU rendering. Previews inside Maya and 3ds Max. Custom shaders. | [Autodesk Arnold](https://www.autodesk.com/products/arnold/overview), [Arnold subscription](https://www.autodesk.com/products/arnold/subscribe), [Fitgap](https://us.fitgap.com/products/008657/autodesk-arnold) |
| V-Ray | Chaos | Proprietary, subscription | V-Ray Solo: $45 per month on the official page (16 Nov 2026). Annual prices depend on current offers. Render nodes are priced separately and were not shown on the page. | Photorealistic renderer. The Solo plan is fixed to one computer and includes all V-Ray integrations (plugins for several 3D tools). | [Chaos V-Ray buy online](https://www.chaos.com/vray/buy-online), [G2](https://www.g2.com/products/v-ray/pricing) |

### Open-source solutions

| Solution | Maker | Licence | Pricing (date checked) | Capabilities | Sources |
|---|---|---|---|---|---|
| MoonRay | DreamWorks Animation, now hosted by the Academy Software Foundation | Apache 2.0 | Free (16 Nov 2026) | Production path tracer used on DreamWorks feature films. Runs on CPU (x86-64 with AVX2) and in a hybrid CPU/GPU mode. Distributed rendering with Arras. | [CG Channel, 2023](https://www.cgchannel.com/2023/03/dreamworks-to-open-source-moonray), [CG Channel, 2026](https://www.cgchannel.com/2026/07/aswf-and-dreamworks-animation-release-moonray-2026-29/) |
| Cycles | Blender project | Apache 2.0 | Free (16 Nov 2026) | Physically based production renderer. Multi-core CPU rendering with SIMD, and GPU rendering. Can be integrated in open-source and commercial software. | [Cycles website](https://www.cycles-renderer.org/), [LinuxLinks](https://linuxlinks.com/cycles-physically-based-production-renderer) |
| appleseed | appleseed team | MIT | Free (16 Nov 2026) | Physically based renderer designed for animation and visual effects. C++ and Python APIs, C++ plugins, Open Shading Language. The most recent news I found is from 2018 to 2021, so the project's current activity must be checked. | [appleseed features](https://appleseed.readthedocs.io/en/latest/features/features.html) |
| pbrt-v4 | Matt Pharr, Wenzel Jakob, Greg Humphreys | Apache 2.0 | Free (16 Nov 2026) | Research and teaching renderer that comes with the book *Physically Based Rendering*. Modern C++, CPU and GPU. A reference more than a production tool. | [pbrt-v4 on GitHub](https://github.com/mmp/pbrt-v4), [LinuxLinks](https://www.linuxlinks.com/pbrt-physically-based-ray-tracing-system/) |

### What these solutions share, and where they fall short for this client

- **What they share:** they are path tracers based on the Monte Carlo method, and they all render on CPU, which fits the client's production machines without graphics cards *(Q4)*.
- **Commercial solutions:** the code is closed. When an image shows an error, the studio must wait for the vendor, as happened with the black dots *(Q1)*, and it cannot add the features it needs *(Q9)*. Licences are also paid per machine. **Conclusion:** 200 RenderMan licences would cost about $119,000, plus about $50,000 per year in maintenance *(Q6)*. This is a large part of the €500,000 budget for the ray tracer *(Q15)*, and the studio still could not change the code.
- **Open-source solutions:** the code is open and free, and MoonRay is already used for feature films. But these are large code bases written by other teams. The client's team of 5 people *(Q12)* would need to understand them, and the studio would depend on an outside community for their future. This does not solve the problem of keeping the software maintainable when someone leaves *(Q16)*.
- **Open question:** why does the client not adopt an open-source renderer such as MoonRay or Cycles? The answer will show what the client really expects from its own ray tracer.

## What is ray tracing?

A ray tracer takes a 3D scene as input: objects with their shapes and materials, light sources and a camera. It produces an image, which is a colour for each pixel. In between, for each pixel, the ray tracer sends a ray from the camera through that pixel into the scene, and finds the first object that the ray hits. From this point, it sends new rays to find out where the light comes from: towards the light sources, to know if the point is in shadow, and in other directions that depend on the material (a mirror reflects light in one direction, a matte surface in all directions). The colour of the pixel is the sum of all the light that arrives at this point. The ray tracer follows the light backwards, from the eye to the lights, because most of the light in a scene never reaches the camera. To get a clean image, it sends many rays per pixel and takes the average: with few rays the image is fast but noisy, and with many rays it is clean but slow. This explains why the client wants a fast preview for designers and a high-quality image for the final render *(Q5)*. This is a first understanding, and I will revise it as I learn more.

### Sources

- Starting resource: Peter Shirley, Trevor David Black and Steve Hollasch, [*Ray Tracing in One Weekend*](https://raytracing.github.io/books/RayTracingInOneWeekend.html), a short free book that builds a simple ray tracer in C++ step by step.
- Reference: Matt Pharr, Wenzel Jakob and Greg Humphreys, [*Physically Based Rendering: From Theory to Implementation*](https://pbr-book.org/), 4th edition, free online. It is the book that comes with pbrt-v4 (see the state of the art).

## What is C++?

### Programming paradigms

C++ is a multi-paradigm language. It supports procedural programming (functions, as in C), object-oriented programming (classes, inheritance, polymorphism), generic programming (templates, code that works with several types) and some functional programming (lambdas).

Compared with the languages I know:

- **Typing:** JavaScript and PHP check types while the program runs. C++ checks them when the code is compiled, so many errors appear before the program starts.
- **Execution:** JavaScript and PHP are run by an engine or an interpreter. C++ is compiled to machine code, which is one reason why it is fast enough for rendering.
- **Objects:** like PHP with Laravel, C++ has classes. PHP uses interfaces, while C++ uses abstract classes with pure virtual functions to play the same role. C++ also allows multiple inheritance, which PHP does not.
- **Copies:** in JavaScript and PHP, an object variable refers to the object, so passing it to a function does not copy it. In C++, objects are copied by default, unless I use a reference or a pointer.
- **Generics:** C++ templates have no real equivalent in JavaScript or PHP.

### What to watch out for

- **Memory:** JavaScript and PHP have a garbage collector. C++ does not: each object has a lifetime that I must control. If I forget to free memory, the program leaks. If I use memory that is already freed, the program can crash or give wrong results.
- **Undefined behaviour:** in C++, some errors, such as reading outside an array or using a variable that is not initialised, do not always stop the program. The program can continue and silently give a wrong result. In JavaScript, the same mistake usually returns `undefined` or throws an error.
- **Floating-point precision:** a ray tracer computes with decimal numbers, which are not exact. A small error can make a ray hit the surface it just left, which creates black dots in the image. This is only a hypothesis for the client's problem *(Q1)*, but it shows why tests and diagnostics matter.
- **Tooling:** C++ has no single standard tool like npm or Composer. Building a project usually needs a build system such as CMake, and compilation can be slow.

Modern C++ gives tools against these traps: RAII (a resource is freed automatically when its owner is destroyed), smart pointers such as `std::unique_ptr`, standard containers such as `std::vector`, compiler warnings and sanitizers that detect memory errors.

### Shaping the domain model

The words of the client's domain should become types in the code, so that developers and the studio share the same vocabulary: `Scene`, `Camera`, `Ray`, `Light`, `Material`, `Shape` and `Image`.

- Small mathematical values, such as a vector, a colour or a ray, can be simple types copied by value. They are cheap to copy and need no memory management.
- `Shape` and `Material` can be abstract classes. A new material or a new shape can then be added without changing the existing code. This answers the client's need to add features *(Q9)* and to accept changes from partner studios *(Q11)*.
- Ownership should be clear: for example, the scene owns its objects through `std::unique_ptr`, so their memory is freed automatically.
- The core of the ray tracer should not depend on Maya. A separate part can convert a Maya scene into our own `Scene`, so the core stays a black box that takes objects and produces an image *(Q8, N4)*.

This is a first understanding, and it will change when we start writing code.

### Sources

- Starting resource: [learncpp.com](https://www.learncpp.com/), a free tutorial that teaches modern C++ from the beginning.
- References: [cppreference.com](https://en.cppreference.com/) for the language and the standard library, and the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) for good practices.
